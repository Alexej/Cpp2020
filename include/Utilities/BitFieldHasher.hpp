#ifndef H_BITFIELDHASHER
#define H_BITFIELDHASHER

#include "../DataStructure/BitField.hpp"
#include <cstddef>
#include <stdint.h>
#include <functional>

/*
    Tried to create another map for reverse lookup, didnt give me any time advantage, pretty sure 
    Im missing something.
*/

namespace Cress::Utilities
{
    using Cress::DataStructure::BitField;
    struct BitFieldHasher
    {
        std::size_t operator()(BitField const& bf) const noexcept
        {
            std::size_t h1 = std::hash<int32_t>{}(bf.getField());
            std::size_t h2 = std::hash<int8_t>{}(bf.size());
            return h1 ^ (h2 << 1); 
        }
    };
}


#endif // H_BITFIELDHASHER