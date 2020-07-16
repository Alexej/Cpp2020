#ifndef H_TREENODE
#define H_TREENODE

#include "CCFEntry.hpp"  
#include <stdint.h>
#include <iostream>
#include <memory>

namespace Cress::DataStructure
{
    class TreeNode
    {
        public:
            std::shared_ptr<TreeNode> leftNode(void) const;
            std::shared_ptr<TreeNode> rightNode(void) const;            
            std::shared_ptr<CCFEntry> data(void) const;
            bool leaf(void) const;
            TreeNode(TreeNode _leftNode, 
                     TreeNode _rightNode);
            TreeNode(char _character, int32_t _frequency);
            const std::shared_ptr<TreeNode> walkTree(int8_t rl) const;
        private:
            std::shared_ptr<CCFEntry> data_ = nullptr;
            bool leaf_ = false;
            std::shared_ptr<TreeNode> leftNode_;
            std::shared_ptr<TreeNode> rightNode_;
    };
}

#endif // H_TREENODE