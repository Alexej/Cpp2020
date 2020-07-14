#include "../../include/DataStructure/CharacterCodeTable.hpp"

namespace Cress::DataStructure
{
    void CharacterCodeTable::addEnty(std::shared_ptr<CCFEntry> entry)
    {
        map_.insert(std::make_pair(entry->character(), entry));
    }
  
    BitField 
    CharacterCodeTable::code(int8_t character)
    {
        return map_[character]->code();
    }

    bool 
    CharacterCodeTable::character(BitField code, int8_t & ch)
    {
        for(auto entry : map_)
            if(entry.second->code() == code)
            {
                ch = entry.first;
                return true; 
            }
        return false;
    }

    int32_t 
    CharacterCodeTable::size() const
    {
        return map_.size();
    }

    std::ostream & 
    operator << (std::ostream & os, const CCFEntry & cce)
    {
        os << cce.character_ << cce.frequency_;
        return os; 
    }

    const std::unordered_map<char, std::shared_ptr<CCFEntry>> & 
    CharacterCodeTable::map(void) const
    {
        return map_;
    }
}