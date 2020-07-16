#ifndef H_TREE
#define H_TREE


#include "TreeNode.hpp"
#include <algorithm>
#include <vector>

namespace Cress::DataStructure
{
    class Tree
    {
        public:
            void sortByChar(void);
            int32_t size(void) const;
            void sortByFrequency(void);
            void push(TreeNode node);
            TreeNode pop(void); 
            std::shared_ptr<TreeNode> rootNode(void);
        private:
            std::vector<TreeNode> tree_;
    };
} 

#endif // H_TREE

