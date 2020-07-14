#ifndef H_BITVECTOR
#define H_BITVECTOR

#include "../BitGetters.hpp"
#include "../Types.hpp"
#include "BitField.hpp"
#include <vector>

namespace Cress::DataStructure
{
    using namespace Cress::Types;
    using namespace Cress::BitGetters;
    class BitVector
    {
        public:
            BitVector(void);
            void addBits(BitField bf);
            int32_t bits(void) const;
            int32_t size(void) const;
            void setNextBit(bool bit);
            const std::vector<int8_t> & vector(void) const;
            void addBitsInNewByte(int16_t & field, int16_t diff);
        private:
            std::vector<int8_t> bitVector;
            int32_t currentBitIndex = 0;
    };
}
#endif // H_BITVECTOR