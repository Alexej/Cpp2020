#include "../../include/DataStructure/HuffmanBinaryTree.hpp"

namespace Cress::DataStructure
{ 
    HuffmanBinaryTree::HuffmanBinaryTree(char _character, uint32_t _frequency)
    {
        data_ = std::make_shared<CCFEntry>(_character, _frequency);
        leaf_ = true;
    }

    HuffmanBinaryTree::HuffmanBinaryTree(HuffmanBinaryTree _leftNode, HuffmanBinaryTree _rightNode)
    {
        leftNode_ = std::make_shared<HuffmanBinaryTree>(_leftNode);
        rightNode_ = std::make_shared<HuffmanBinaryTree>(_rightNode);
        data_ = std::make_shared<CCFEntry>(leftNode_->data()->frequency() + 
                                           rightNode_->data()->frequency());
    } 

    std::shared_ptr<HuffmanBinaryTree> 
    HuffmanBinaryTree::leftNode() const
    {
        return leftNode_;
    }

    std::shared_ptr<HuffmanBinaryTree> 
    HuffmanBinaryTree::rightNode() const
    {
        return rightNode_;
    }  
 
    std::shared_ptr<CCFEntry> 
    HuffmanBinaryTree::data(void) const
    {
        return data_;
    } 

    bool 
    HuffmanBinaryTree::leaf(void) const
    {
        return leaf_;
    }

    const std::shared_ptr<HuffmanBinaryTree> 
    HuffmanBinaryTree::walkTree(int8_t rl) const
    {
        return rl == 0 ? leftNode_ : rightNode_;
    }
}    