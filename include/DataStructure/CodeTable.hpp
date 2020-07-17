#ifndef H_CODETABLE
#define H_CODETABLE

#include "NodeData.hpp"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <utility>
#include <ostream>

namespace Cpp2020::DataStructure
{
    class CodeTable
    {
        public: 
            BitField code(int8_t character);
            int32_t size(void) const;
            bool character(const BitField & code, int8_t & ch) const;
            void addEnty(std::shared_ptr<NodeData> entry);
            const std::unordered_map<char, std::shared_ptr<NodeData>> & map(void) const;
        private:
            std::unordered_map<char, std::shared_ptr<NodeData>> map_;
    };
}

#endif // H_CODETABLE