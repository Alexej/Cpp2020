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
        ++length_;
        bitField_ <<= 1;
        bitField_ ^= bit;
        return *this;
    } 

    int32_t 
    BitField::getField(void) const
    {
        return bitField_;
    }

    int8_t 
    BitField::size(void) const
    {
        return length_;
    }

    bool operator == (const BitField & rhs, const BitField & lhs)
    {
        return (rhs.size() == lhs.size()) && (rhs.getField() == lhs.getField());
    }   
}
 