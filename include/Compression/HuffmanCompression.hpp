#ifndef H_HUFFMANCOMPRESSION
#define H_HUFFMANCOMPRESSION

#include "../FileHandling/FileIO.hpp"
#include "../DataStructure/CharacterCodeTable.hpp"
#include "../DataStructure/HuffmanBinaryTree.hpp"
#include "../DataStructure/BitField.hpp"
#include "../DataStructure/BitVector.hpp"
#include "../DataStructure/Queue.hpp"
#include <list>
#include <iostream>

namespace Cress::Compression
{
    using namespace Cress::DataStructure;
    using namespace Cress::FileHandling;
    enum class Mode{DECOMRESSION, COMPRESSION};

    struct HeaderInfo
    {
        HeaderInfo(int32_t gho, int32_t cdlib);
        int32_t globalHeaderOffset;
        int32_t compressedDataLengthInBits;
    };

    class HuffmanCompression
    {
        public:
            void compress(void);
            void fillQueue(void);
            void createTree(void);
            void decompress(int32_t gho, int32_t compressedDataLengthInBits);
            void createTable(void);
            void startCompressing(void);
            void startDecompressing(void);
            HeaderInfo readHeader(void);
            HuffmanCompression(std::string filePath, Mode mode);
            void traverseTree(std::shared_ptr<HuffmanBinaryTree> node, BitField bf);
            int32_t readInteger(int32_t & offset);
            int32_t readInteger(int32_t & offset, int32_t & globalHeaderOffset);
        private:
            std::list<int8_t> byteList;
            Queue queue;
            CharacterCodeTable cct;
            FileIO io;
            std::shared_ptr<HuffmanBinaryTree> rootNode;
    };
}

#endif // H_HUFFMAN