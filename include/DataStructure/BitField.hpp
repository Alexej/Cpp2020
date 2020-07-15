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
        /*
           [TOPIC](12) benutzerdefinierte Datentypen: operator overloading
        */
            friend bool operator == (const BitField & rhs, 
                                     const BitField & lhs);
        private:
            int32_t bitField = 0;
            int8_t length = 0;
    };
}
#endif // H_BITFIELD