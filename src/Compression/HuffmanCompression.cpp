#include "../../include/Compression/HuffmanCompression.hpp"

namespace Cress::Compression 
{
    HuffmanCompression::HuffmanCompression(std::string file, Mode mode)
    : queue(), 
      cct(), 
      io(file)
    {
        if(mode == Mode::COMPRESSION)
            startCompressing();
        else if(mode == Mode::DECOMRESSION)
            startDecompressing();
    }

    void 
    HuffmanCompression::fillQueue(void)
    {
        while(byteList.size() > 0)
        {
            int8_t currentByte = byteList.front();
            int32_t frequency = std::count(byteList.begin(), byteList.end(), currentByte);
            byteList.remove(currentByte);
            queue.push(HuffmanBinaryTree(currentByte, frequency));
        }
    }

    void 
    HuffmanCompression::createTree(void)
    {
        queue.sortByChar();
        while(queue.size() > 1)
        {
            queue.sortByFrequency();
            HuffmanBinaryTree hbt1 = queue.pop();
            HuffmanBinaryTree hbt2 = queue.pop(); 
            HuffmanBinaryTree newNode(hbt1, hbt2);
            queue.push(newNode);
        }
        rootNode = queue.rootNode();
    }

    void 
    HuffmanCompression::createTable(void)
    {
        traverseTree(rootNode->leftNode(), BitField(0));
        traverseTree(rootNode->rightNode(), BitField(1));
    }

    void 
    HuffmanCompression::traverseTree(std::shared_ptr<HuffmanBinaryTree> node, BitField bf)
    {
        if(node->leaf())
        {
            node->data()->setCode(bf);
            cct.addEnty(node->data());
        }
        else
        {
            BitField bfl(bf);
            BitField bfr(bf);
            bfl.append(0);
            bfr.append(1);
            traverseTree(node->leftNode(), bfl);
            traverseTree(node->rightNode(), bfr);
        }
    }
  
    void 
    HuffmanCompression::compress(void)  
    {
        BitVector bv;
        for(auto& ch : io.data())
        {
            BitField code = cct.code(ch);
            bv.addBits(code);
        } 
        io.writeFile(cct.map(), io.filename(), bv);
    }
 
    void  
    HuffmanCompression::startCompressing(void)
    {
        for(auto& byte : io.data())
            byteList.push_back(byte);
        fillQueue();
        createTree();
        createTable(); 
        compress(); 
    }

    void 
    HuffmanCompression::startDecompressing(void)
    {
        HeaderInfo gho = readHeader();
        createTree();
        createTable();
        decompress(gho.globalHeaderOffset, gho.compressedDataLengthInBits);
    }

    void 
    HuffmanCompression::decompress(int32_t gho, int32_t compressedDataLengthInBites) 
    {
        std::vector<int8_t> decompressedCode;
        int32_t globalBitOffset = 0;
        std::shared_ptr<HuffmanBinaryTree> currentNode = rootNode;
        for(std::size_t i = gho; i < io.data().size(); ++i)
        {
            int8_t currentCharacter = io.data()[i];
            for(int8_t bitCounter = INT8-1; (bitCounter >= 0) && 
            (globalBitOffset < compressedDataLengthInBites); --bitCounter)
            {
                ++globalBitOffset;
                currentNode = currentNode->walkTree(((currentCharacter >> bitCounter) & 1));
                if(currentNode->leaf())
                {
                    decompressedCode.push_back(currentNode->data()->character());
                    currentNode = rootNode;
                }
            }
        }
        io.writeFile(io.filename(), decompressedCode);
    }

    int32_t  
    HuffmanCompression::readInteger(int32_t & offset)
    {
        std::string integerString = "";
        for(std::size_t i = offset; i < io.data().size(); ++i)
        {
            if(io.data()[i] == ' ')
                break;
            integerString += io.data()[i];
            ++offset;
        }
        return std::stoi(integerString);
    }

    int32_t 
    HuffmanCompression::readInteger(int32_t & offset, int32_t & globalHeaderOffset)
    {
        std::string integerString = "";
        int8_t nextChar = io.data()[offset];
        while(nextChar != ' ')
        {
            nextChar = io.data()[offset];
            integerString += nextChar;
            ++globalHeaderOffset;
            ++offset;
        }
        return std::stoi(integerString);
    }

    HeaderInfo 
    HuffmanCompression::readHeader(void)
    {
        int32_t length;
        int32_t offset = 0;
        int32_t cdsib;
        cdsib = readInteger(offset);
        ++offset;
        length = readInteger(offset);
        int32_t internIndex = offset+1;
        for(int32_t headerOffset = 0; headerOffset < length; ++headerOffset)
        {
            int8_t character = io.data()[internIndex];
            int32_t j = internIndex+1;
            ++offset;
            int32_t frequency = readInteger(j, offset);
            queue.push(HuffmanBinaryTree(character, frequency));
            internIndex+=(j-internIndex);
        }
        return HeaderInfo(offset+2, cdsib); // remove magic number somehow
    }

    HeaderInfo::HeaderInfo(int32_t gho, int32_t cdlib)
    : globalHeaderOffset(gho),
      compressedDataLengthInBits(cdlib)
    {}
}
