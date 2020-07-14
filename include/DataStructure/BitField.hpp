#ifndef H_BITFIELD
#define H_BITFIELD

#include <stdint.h>

namespace Cress::DataStructure
{
    class BitField
    {
        public:
            BitField(){}
            explicit BitField(int8_t bit);
            int32_t getField(void) const;
            void append(int8_t bit);
            int8_t size(void) const;
        public:
            friend bool operator == (const BitField & rhs, 
                                     const BitField & lhs);
        private:
            int32_t bitField = 0;
            int8_t length = 0;
    };
}
#endif // H_BITFIELD