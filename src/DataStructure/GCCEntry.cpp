#include "../../include/DataStructure/CCFEntry.hpp"

namespace Cress::DataStructure
{
    CCFEntry::CCFEntry(BitField _code, int8_t _character, int32_t _frequency)
    : character_(_character),
      code_(_code), 
      frequency_(_frequency)
    {}

    CCFEntry::CCFEntry(int8_t _character, int32_t _frequency)
    : character_(_character),
      frequency_(_frequency)
    {}


    BitField 
    CCFEntry::code(void) const
    {
        return code_;
    }

    int8_t 
    CCFEntry::character(void) const
    {
        return character_;
    }

    int32_t 
    CCFEntry::frequency(void) const
    {
        return frequency_;
    }

    void 
    CCFEntry::setCode(BitField code)
    {
        code_ = code;
    }

    void 
    CCFEntry::setFrequency(int32_t freq)
    {
        frequency_ = freq;
    }

   CCFEntry::CCFEntry(int32_t _frequency)
    : frequency_(_frequency)
    {}
}