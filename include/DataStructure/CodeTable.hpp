#ifndef H_CODETABLE
#define H_CODETABLE

#include "CCFEntry.hpp"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <utility>
#include <ostream>

namespace Cress::DataStructure
{
    class CodeTable
    {
        public:
            BitField code(int8_t character);
            int32_t size() const;
            bool character(BitField code, int8_t & ch);
            void addEnty(std::shared_ptr<CCFEntry> entry);
            const std::unordered_map<char, std::shared_ptr<CCFEntry>> & map(void) const;
        private:
            std::unordered_map<char, std::shared_ptr<CCFEntry>> map_;
    };
}

#endif // H_CODETABLE