#include "../../include/DataStructure/HuffmanTree.hpp"

namespace Cress::DataStructure
{
    TreeNode 
    HuffmanTree::pop(void) 
    { 
        TreeNode hbt = tree_.back();
        tree_.pop_back();
        return hbt;
    }

    void 
    HuffmanTree::push(TreeNode node) 
    { 
        tree_.push_back(node);
    }

    void 
    HuffmanTree::sortByFrequency(void) 
    {        
        std::sort(tree_.begin(), tree_.end(), [](const TreeNode & lhs, const TreeNode & rhs) {
            return lhs.data()->frequency() > rhs.data()->frequency();
        });
    }

    void 
    HuffmanTree::sortByChar(void) 
    {        
        std::sort(tree_.begin(), tree_.end(), [](const TreeNode & lhs, const TreeNode & rhs) {
            return lhs.data()->character() > rhs.data()->character();
        });
    }

    int32_t 
    HuffmanTree::size(void) const
    { 
        return tree_.size();
    }

    std::shared_ptr<TreeNode> 
    HuffmanTree::rootNode(void)
    {
        return std::make_shared<TreeNode>(tree_.back());
    }

    void HuffmanTree::traverseTree(std::shared_ptr<TreeNode> node,
                                   BitField bf, CodeTable & ct)
    {
        if(node->leaf())
        {
            node->data()->setCode(bf);
            ct.addEnty(node->data());
        }
        else
        {
            DataStructure::BitField bfl(bf);
            DataStructure::BitField bfr(bf);
            traverseTree(node->leftNode(), bfl.append(0), ct);
            traverseTree(node->rightNode(), bfr.append(1), ct);
        }
    }
}  