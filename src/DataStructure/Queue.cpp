#include "../../include/DataStructure/Queue.hpp"

namespace Cress::DataStructure
{
    HuffmanBinaryTree Queue::pop(void) 
    { 
        HuffmanBinaryTree hbt = queue.back();
        queue.pop_back();
        return hbt;
    }

    void 
    Queue::push(HuffmanBinaryTree node) 
    {
        queue.push_back(node);
    }

    void 
    Queue::sortByFrequency(void) 
    {        
        std::sort(queue.begin(), queue.end(), [](const HuffmanBinaryTree & lhs, const HuffmanBinaryTree & rhs) {
            return lhs.data()->frequency() > rhs.data()->frequency();
        });
    }

    void 
    Queue::sortByChar(void) 
    {        
        std::sort(queue.begin(), queue.end(), [](const HuffmanBinaryTree & lhs, const HuffmanBinaryTree & rhs) {
            return lhs.data()->character() > rhs.data()->character();
        });
    }

    int32_t 
    Queue::size(void) const
    { 
        return queue.size();
    }

    const HuffmanBinaryTree & 
    Queue::operator[](int32_t i)
    {
        return queue[i]; 
    }

    std::shared_ptr<HuffmanBinaryTree> 
    Queue::rootNode(void)
    {
        return std::make_shared<HuffmanBinaryTree>(queue.back());
    }
}