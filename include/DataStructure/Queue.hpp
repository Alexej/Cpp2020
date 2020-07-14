#ifndef H_CHARACTERQUEUE
#define H_CHARACTERQUEUE


#include "HuffmanBinaryTree.hpp"
#include <algorithm>
#include <vector>

namespace Cress::DataStructure
{
    class Queue
    {
        public:
            void sortByChar(void);
            int32_t size(void) const;
            void sortByFrequency(void);
            void push(HuffmanBinaryTree node);
            HuffmanBinaryTree pop(void); 
            std::shared_ptr<HuffmanBinaryTree> rootNode(void);
        public:
            const HuffmanBinaryTree & operator[](int32_t i);
        private:
            std::vector<HuffmanBinaryTree> queue;
    };
} 

#endif // H_CHARACTERQUEUE

