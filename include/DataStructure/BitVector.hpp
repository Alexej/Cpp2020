#ifndef H_BITVECTOR
#define H_BITVECTOR

#include "../BitGetters.hpp"
#include "../Macros.hpp"
#include "BitField.hpp"
#include <vector>

namespace Cress::DataStructure
{
    class BitVector
    {
        public:
            BitVector(void);
            void addBits(const BitField & bf);
            int32_t bits(void) const;
            int32_t size(void) const;
            void setNextBit(bool bit);
            const std::vector<int8_t> & vector(void) const;
            void addBitsInNewByte(int16_t & field, int16_t diff);
        private:
            std::vector<int8_t> bitVector_;
            int32_t currentBitIndex_ = 0;
    };
}
#endif // H_BITVECTOR