#include "../../include/DataStructure/BitField.hpp"

namespace Cress::DataStructure
{
    BitField::BitField()
    {}

    BitField::BitField(bool bit)
    {
        append(bit);
    }
    
    BitField  
    BitField::append(bool bit)
    {
        ++length;
        bitField <<= 1;
        bitField ^= bit;
        return *this;
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
        return (rhs.size() == lhs.size()) && (rhs.getField() == lhs.getField());
    }   
}
 