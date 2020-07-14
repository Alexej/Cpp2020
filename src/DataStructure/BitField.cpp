#include "../../include/DataStructure/BitField.hpp"

namespace Cress::DataStructure
{
    BitField::BitField(int8_t bit)
    {
        append(bit);
    }
    
    void  
    BitField::append(int8_t bit)
    {
        ++length;
        bitField <<= 1;
        bitField ^= bit;
    } 

    int32_t 
    BitField::getField(void) const
    {
        return bitField;
    }

    int8_t 
    BitField::size(void) const
    {
        return length;
    }

    bool operator == (const BitField & rhs, const BitField & lhs)
    {
        if(rhs.size() != lhs.size())
            return false;
        return rhs.getField() == lhs.getField();
    }
}
