#ifndef H_HUFFMANTREE
#define H_HUFFMANTREE


#include "CodeTable.hpp"
#include "TreeNode.hpp"
#include <algorithm>
#include <vector>

namespace Cpp2020::DataStructure
{
    class HuffmanTree
    {
        public:
            void sortByChar(void);
            void sortByFrequency(void);
            int32_t size(void) const;
            void push(TreeNode node);
            TreeNode pop(void); 
            std::shared_ptr<TreeNode> rootNode(void);
            void traverseTree(const std::shared_ptr<TreeNode> & node, BitField bf, CodeTable & ct);
        private:
            std::vector<TreeNode> tree_;
    };
} 

#endif // H_HUFFMANTREE

