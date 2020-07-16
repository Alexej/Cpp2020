#include "../../include/DataStructure/CodeTable.hpp"

namespace Cress::DataStructure
{
    void CodeTable::addEnty(std::shared_ptr<CCFEntry> entry)
    {
        map_.insert(std::make_pair(entry->character(), entry));
    }
  
    BitField 
    CodeTable::code(int8_t character)
    {
        return map_[character]->code();
    }

    bool 
    CodeTable::character(BitField code, int8_t & ch)
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
    CodeTable::size() const
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
    CodeTable::map(void) const
    {
        return map_;
    }
}