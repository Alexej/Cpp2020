#ifndef H_CHARACTERCODEENTRY
#define H_CHARACTERCODEENTRY

#include "BitField.hpp"
#include <stdint.h>
#include <string>

namespace Cress::DataStructure
{
    class CCFEntry // Character, Code, Frequency Entry
    {
        public:
            int8_t character(void) const;
            int32_t frequency(void) const;
            BitField code(void) const;
            void setCode(BitField code);
            void setFrequency(int32_t freq);
            explicit CCFEntry(int32_t _frequency);
            CCFEntry(int8_t _character, int32_t _frequency);
            CCFEntry(BitField _code, int8_t _character, int32_t _frequency);
        public:
            friend std::ostream& operator << (std::ostream & os, 
                                              const CCFEntry & dt);            
        private:
            int8_t character_;
            BitField code_;
            int32_t frequency_;
    };
}

#endif // H_CHARACTERCODEENTRY