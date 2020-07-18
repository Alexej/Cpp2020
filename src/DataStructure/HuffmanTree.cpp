#include "../../include/DataStructure/HuffmanTree.hpp"

namespace Cpp2020::DataStructure
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

    //[TOPIC][1](10) Kontrollfluß: fortgeschrittene Kontrollstrukturen: Lambda
    //[TOPIC](22) wichtige Algorithmen der C++-Standardbibliothek
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

    //[TOPIC](9) Kontrollfluß: grundlegende Kontrollstrukturen*, Rekursion
    void HuffmanTree::traverseTree(const std::shared_ptr<TreeNode> & node,
                                   BitField bf, CodeTable & ct)
    {
        if(node->leaf())
        {
            node->data()->code(bf);
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