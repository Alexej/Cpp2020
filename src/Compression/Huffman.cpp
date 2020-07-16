#include "../../include/Compression/Huffman.hpp"

namespace Cress::Compression 
{
    Huffman::Huffman(std::string file, Mode mode)
    : queue(), 
      cct(), 
      io(file)
    {
        if(mode == Mode::COMPRESSION)
            startCompressing();
        else if(mode == Mode::DECOMRESSION)
            startDecompressing();
    }

    void Huffman::
    copyData(void)
    {
        for(std::size_t i = 0; i < io.size(); ++i)
            data_.push_back(*((char*)io.data() + i));
    }

    void 
    Huffman::fillQueue(void)
    {
        std::list<int8_t> byteList;
        for(auto byte : data_)
            byteList.push_back(byte);
        while(byteList.size() > 0)
        {
            int8_t currentByte = byteList.front();
            int32_t frequency = std::count(byteList.begin(), byteList.end(), currentByte);
            byteList.remove(currentByte);
            queue.push(HuffmanBinaryTree(currentByte, frequency));
        }
    }

    void 
    Huffman::createTree(void)
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
    Huffman::createTable(void)
    {
        traverseTree(rootNode->leftNode(), BitField(0));
        traverseTree(rootNode->rightNode(), BitField(1));
    }

    void 
    Huffman::traverseTree(std::shared_ptr<HuffmanBinaryTree> node, BitField bf)
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
            traverseTree(node->leftNode(), bfl.append(0));
            traverseTree(node->rightNode(), bfr.append(1));
        }
    }
  
    void 
    Huffman::compress(void)  
    {
        BitVector bv;
        for(auto ch : data_)
        {
            BitField code = cct.code(ch);
            bv.addBits(code);
        } 
        io.writeFile(cct.map(), io.filename(), bv);
    }
 
    void  
    Huffman::startCompressing(void)
    {
        copyData();
        fillQueue();
        createTree();
        createTable(); 
        compress(); 
    }

    void 
    Huffman::startDecompressing(void)
    {
        copyData();
        headerInfo = readHeader();
        createTree();
        createTable();
        decompress();
    }

    void 
    Huffman::decompress() 
    {
        std::vector<int8_t> decompressedCode;
        int32_t globalBitOffset = 0;
        std::shared_ptr<HuffmanBinaryTree> currentNode = rootNode;
        for(std::size_t i = headerInfo.globalHeaderOffset; i < data_.size(); ++i)
        {
            int8_t currentCharacter = data_[i];
            for(int8_t bitCounter = INT8-1; (bitCounter >= 0) && 
            (globalBitOffset < headerInfo.compressedDataLengthInBits); --bitCounter)
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
    Huffman::readInteger(int32_t & offset)
    {
        std::string integerString = "";
        for(std::size_t i = offset; i < data_.size(); ++i)
        {
            if(data_[i] == ' ')
                break;
            integerString += data_[i];
            ++offset;
        }
        return std::stoi(integerString);
    }

    int32_t 
    Huffman::readInteger(int32_t & offset, int32_t & globalHeaderOffset)
    {
        std::string integerString = "";
        int8_t nextChar = data_[offset];
        while(nextChar != ' ')
        {
            nextChar = data_[offset];
            integerString += nextChar;
            ++globalHeaderOffset;
            ++offset;
        }
        return std::stoi(integerString);
    }

    HeaderInfo 
    Huffman::readHeader(void)
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
            int8_t character = data_[internIndex];
            int32_t j = internIndex+1;
            ++offset;
            int32_t frequency = readInteger(j, offset);
            queue.push(HuffmanBinaryTree(character, frequency));
            internIndex+=(j-internIndex);
        }
        return HeaderInfo(offset+2, cdsib); // remove magic number somehow
    }
}