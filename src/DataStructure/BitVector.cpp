#include "../../include/DataStructure/BitVector.hpp"

namespace Cress::DataStructure
{
    BitVector::BitVector(void)
    {
        bitVector.push_back(0);
    }

    void 
    BitVector::addBits(BitField bf)
    {
        int32_t field = bf.getField();
        for(int32_t i = static_cast<int32_t>(bf.size()-1); i >= 0; --i)
        {
            setNextBit((field & mask32[i]) >> i);
        }
    }

    void  
    BitVector::setNextBit(bool bit)
    {
        int32_t cbi = bitVector.size();  
        int32_t spaceInCurrentByte = (cbi * INT8) - currentBitIndex;
        if(spaceInCurrentByte == 0)
        {
            bitVector.push_back(0);
            spaceInCurrentByte = INT8;
        }
        if(bit)
            bitVector.back() ^= mask8[spaceInCurrentByte-1];
        ++currentBitIndex;
    }

    int32_t 
    BitVector::bits(void) const
    {
        return currentBitIndex;
    }

    int32_t 
    BitVector::size(void) const
    {
        return bitVector.size();
    }

    const std::vector<int8_t> & 
    BitVector::vector(void) const
    {
        return bitVector;
    }
}
