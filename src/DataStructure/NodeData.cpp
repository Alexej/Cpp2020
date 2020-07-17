#include "../../include/DataStructure/NodeData.hpp"

namespace Cpp2020::DataStructure
{
    NodeData::NodeData(const BitField & _code, int8_t _character, 
                       int32_t _frequency)
    : character_(_character),
      code_(_code), 
      frequency_(_frequency)
    {}

    NodeData::NodeData(int8_t _character, int32_t _frequency)
    : character_(_character),
      frequency_(_frequency)
    {}

   NodeData::NodeData(int32_t _frequency)
    : frequency_(_frequency)
    {}
 
    BitField 
    NodeData::code(void) const
    {
        return code_;
    }

    int8_t 
    NodeData::character(void) const
    {
        return character_;
    }

    int32_t 
    NodeData::frequency(void) const
    {
        return frequency_;
    }

    void 
    NodeData::code(const BitField & code)
    {
        code_ = code;
    }

}