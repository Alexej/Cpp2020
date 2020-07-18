#ifndef H_BITFIELD
#define H_BITFIELD

#include <stdint.h>

namespace Cpp2020::DataStructure
{
    class BitField
    {
        public:
            BitField();
            explicit BitField(bool bit);
            int32_t field(void) const;
            int8_t size(void) const;
            BitField append(bool bit);
        public:
            //[TOPIC](12) benutzerdefinierte Datentypen: operator overloading
            friend bool operator == (const BitField & rhs, const BitField & lhs);
        private:
            int32_t bitField_ = 0;
            int8_t length_ = 0;
    };
}
#endif // H_BITFIELD