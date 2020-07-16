#include "../../include/DataStructure/Tree.hpp"

namespace Cress::DataStructure
{
    TreeNode Tree::pop(void) 
    { 
        TreeNode hbt = tree_.back();
        tree_.pop_back();
        return hbt;
    }

    void 
    Tree::push(TreeNode node) 
    { 
        tree_.push_back(node);
    }

    void 
    Tree::sortByFrequency(void) 
    {        
        std::sort(tree_.begin(), tree_.end(), [](const TreeNode & lhs, const TreeNode & rhs) {
            return lhs.data()->frequency() > rhs.data()->frequency();
        });
    }

    void 
    Tree::sortByChar(void) 
    {        
        std::sort(tree_.begin(), tree_.end(), [](const TreeNode & lhs, const TreeNode & rhs) {
            return lhs.data()->character() > rhs.data()->character();
        });
    }

    int32_t 
    Tree::size(void) const
    { 
        return tree_.size();
    }

    const TreeNode & 
    Tree::operator[](int32_t i)
    {
        return tree_[i]; 
    }

    std::shared_ptr<TreeNode> 
    Tree::rootNode(void)
    {
        return std::make_shared<TreeNode>(tree_.back());
    }
}