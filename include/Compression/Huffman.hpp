#ifndef H_Huffman
#define H_Huffman

#include "../DataStructure/HeaderInfo.hpp"
#include "../Interfaces/ICompression.hpp"
#include "../FileHandling/FileIO.hpp"
#include "../DataStructure/CodeTable.hpp"
#include "../DataStructure/TreeNode.hpp"
#include "../DataStructure/BitField.hpp"
#include "../DataStructure/BitVector.hpp"
#include "../DataStructure/Tree.hpp"
#include <list>
#include <iostream>

namespace Cress::Compression
{
    using namespace Cress::DataStructure;
    using namespace Cress::FileHandling;
    using namespace Cress::Interfaces;
    enum class Mode{DECOMRESSION, COMPRESSION};
    class Huffman : protected ICompression
    {
        public:
            void compress(void) override; 
            void decompress() override;
            void fillQueue(void);
            void createTree(void);
            void createTable(void);
            void startCompressing(void);
            void startDecompressing(void);
            void copyData(void);
            void readHeader(void);
            Huffman(std::string filePath, Mode mode);
            void traverseTree(std::shared_ptr<TreeNode> node, BitField bf);
            int32_t readInteger(int32_t & offset);
            int32_t readInteger(int32_t & offset, int32_t & globalHeaderOffset);
        private:
            std::vector<char> data_;
            Tree queue_;
            CodeTable cct_;
            FileIO io_;
            std::shared_ptr<TreeNode> rootNode_;
            HeaderInfo headerInfo_;
    };
}

#endif // H_HUFFMAN