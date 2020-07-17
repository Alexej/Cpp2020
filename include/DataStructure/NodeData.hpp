#ifndef H_NODEDATA
#define H_NODEDATA

#include "BitField.hpp"
#include <stdint.h>
#include <string>

namespace Cress::DataStructure
{
    class NodeData // Character, Code, Frequency Entry
    {
        public:
            int8_t character(void) const;
            int32_t frequency(void) const;
            BitField code(void) const;
            void setCode(const BitField & code);
            explicit NodeData(int32_t _frequency);
            NodeData(int8_t _character, int32_t _frequency);
            NodeData(const BitField & _code, int8_t _character, int32_t _frequency);
        public:
            friend std::ostream& operator << (std::ostream & os, 
                                              const NodeData & dt);            
        private:
            int8_t character_;
            BitField code_;
            int32_t frequency_;
    };
}

#endif // H_NODEDATA