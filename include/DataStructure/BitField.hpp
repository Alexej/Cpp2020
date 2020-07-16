#ifndef H_BITFIELD
#define H_BITFIELD

#include <stdint.h>

namespace Cress::DataStructure
{
    class BitField
    {
        public:
            BitField();
            explicit BitField(bool bit);
            int32_t getField(void) const;
            int8_t size(void) const;
            BitField append(bool bit);
        public:
            friend bool operator == (const BitField & rhs, 
                                     const BitField & lhs);
        private:
            int32_t bitField_ = 0;
            int8_t length_ = 0;
    };
}
#endif // H_BITFIELD