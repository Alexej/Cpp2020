#ifndef H_BINARYTREE
#define H_BINARYTREE

#include "CCFEntry.hpp" 
#include <stdint.h>
#include <iostream>
#include <memory>

namespace Cress::DataStructure
{
    enum class NodeState {LEFT, RIGHT, CHAR, ROOT};
    class HuffmanBinaryTree
    {
        public:
            std::shared_ptr<HuffmanBinaryTree> leftNode(void) const;
            std::shared_ptr<HuffmanBinaryTree> rightNode(void) const;            
            std::shared_ptr<CCFEntry> data(void) const;
            bool leaf(void) const;
            HuffmanBinaryTree(HuffmanBinaryTree _leftNode, 
                              HuffmanBinaryTree _rightNode);
            HuffmanBinaryTree(char _character, uint32_t _frequency);
            const std::shared_ptr<HuffmanBinaryTree> walkTree(int8_t rl) const;
        private:
            bool leaf_ = false;
            std::shared_ptr<HuffmanBinaryTree> leftNode_;
            std::shared_ptr<HuffmanBinaryTree> rightNode_;
            std::shared_ptr<CCFEntry> data_ = nullptr;
    };
}

#endif // H_BINARYTREE