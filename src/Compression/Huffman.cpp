#include "../../include/Compression/Huffman.hpp"

namespace Cress::Compression 
{
    Huffman::Huffman(std::string file, Mode mode)
    : queue_(), 
      cct_(), 
      io_(file)
    {
        if(mode == Mode::COMPRESSION)
            startCompressing(); 
        else if(mode == Mode::DECOMRESSION)
            startDecompressing();
    }

    void 
    Huffman::copyData(void)
    {
        for(std::size_t i = 0; i < io_.size(); ++i)
            data_.push_back(*((char*)io_.data() + i));
    }

    void 
    Huffman::fillQueue(void)
    {
        std::list<int8_t> byteList;
        for(auto byte : data_)
            byteList.push_back(byte);
        
        // Very Bad, did it just so i can use a template function
        for(auto& el : Utilities::FrequencyCounter<int8_t, int32_t>(byteList))
            queue_.push(DataStructure::TreeNode(el.first, el.second));
    }

    void 
    Huffman::createTree(void)
    {
        queue_.sortByChar();
        while(queue_.size() > 1)
        {
            queue_.sortByFrequency();
            DataStructure::TreeNode hbt1 = queue_.pop();
            DataStructure::TreeNode hbt2 = queue_.pop(); 
            DataStructure::TreeNode newNode(hbt1, hbt2);
            queue_.push(newNode);
        }
        rootNode_ = queue_.rootNode();
    }

    void 
    Huffman::createTable(void)
    {
        traverseTree(rootNode_->leftNode(), DataStructure::BitField(0));
        traverseTree(rootNode_->rightNode(), DataStructure::BitField(1)); 
    }

    void 
    Huffman::traverseTree(std::shared_ptr<DataStructure::TreeNode> node,
                          DataStructure::BitField bf)
    {
        if(node->leaf())
        {
            node->data()->setCode(bf);
            cct_.addEnty(node->data());
        }
        else
        {
            DataStructure::BitField bfl(bf);
            DataStructure::BitField bfr(bf);
            traverseTree(node->leftNode(), bfl.append(0));
            traverseTree(node->rightNode(), bfr.append(1));
        }
    }
  
    void 
    Huffman::compress(void)  
    {
        DataStructure::BitVector bv;
        for(auto ch : data_)
        {
            DataStructure::BitField code = cct_.code(ch);
            bv.addBits(code);
        } 
        io_.writeFile(cct_.map(), io_.filename(), bv);
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
        readHeader();
        createTree();
        createTable();
        decompress();
    }

    void 
    Huffman::decompress(void) 
    {
        std::vector<int8_t> decompressedCode;
        int32_t globalBitOffset = 0;
        std::shared_ptr<DataStructure::TreeNode> currentNode = rootNode_;
        for(std::size_t i = headerInfo_.globalHeaderOffset_; i < data_.size(); ++i)
        {
            int8_t currentCharacter = data_[i];
            for(int8_t bitCounter = INT8-1; (bitCounter >= 0) && 
            (globalBitOffset < headerInfo_.compressedDataLengthInBits_); --bitCounter)
            {
                ++globalBitOffset;
                currentNode = currentNode->walkTree(((currentCharacter >> bitCounter) & 1));
                if(currentNode->leaf())
                {
                    decompressedCode.push_back(currentNode->data()->character());
                    currentNode = rootNode_;
                }
            }
        }
        io_.writeFile(io_.filename(), decompressedCode);
    }

    int32_t  
    Huffman::readInteger(int32_t & offset)
    {
        std::string integerString = "";
        for(std::size_t i = offset; i < data_.size(); ++i, ++offset)
        {
            if(data_[i] == ' ')
                break;
            integerString += data_[i];
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

    void 
    Huffman::readHeader(void)
    {
        int32_t length;
        int32_t offset = 0;
        int32_t cdsib;
        cdsib = readInteger(offset);
        ++offset;
        length = readInteger(offset);
        int32_t internIndex = offset+1;
        for(int32_t headerOffset = 0; headerOffset < length; ++headerOffset, ++offset)
        {   int32_t j = internIndex+1;
            int8_t character = data_[internIndex];
            int32_t frequency = readInteger(j, offset);
            queue_.push(DataStructure::TreeNode(character, frequency));
            internIndex+=(j-internIndex);
        }
        headerInfo_ = DataStructure::HeaderInfo(offset+2, cdsib);
    }
}
