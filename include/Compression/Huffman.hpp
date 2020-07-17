#ifndef H_Huffman
#define H_Huffman

#include "../Utilities/FrequencyCounter.hpp"
#include "../DataStructure/HeaderInfo.hpp"
#include "../Interfaces/ICompression.hpp"
#include "../DataStructure/CodeTable.hpp"
#include "../FileHandling/FileIO.hpp"
#include "../DataStructure/TreeNode.hpp"
#include "../DataStructure/BitField.hpp"
#include "../DataStructure/BitVector.hpp"
#include "../DataStructure/HuffmanTree.hpp"
#include <list>
#include <iostream>

namespace Cress::Compression
{
    enum class Mode{DECOMRESSION, COMPRESSION};
    class Huffman : protected Interfaces::ICompression
    {
        public:
            Huffman(const std::string & filePath, Mode mode);
            void compress(void) override; 
            void decompress(void) override;
            void fillQueue(void);
            void createTree(void);
            void createTable(void);
            void startCompressing(void);
            void startDecompressing(void);
            void copyData(void);
            void readHeader(void);
            int32_t readInteger(int32_t & offset);
            int32_t readInteger(int32_t & offset, int32_t & globalHeaderOffset);
        private:
            std::vector<int8_t> data_;
            DataStructure::HuffmanTree tree_; 
            DataStructure::CodeTable ct_;
            FileHandling::FileIO io_;
            std::shared_ptr<DataStructure::TreeNode> rootNode_;
            DataStructure::HeaderInfo headerInfo_;
    };
}

#endif // H_HUFFMAN