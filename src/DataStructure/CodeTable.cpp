#include "../../include/DataStructure/CodeTable.hpp"

namespace Cpp2020::DataStructure
{
    void CodeTable::addEnty(std::shared_ptr<NodeData> entry)
    {
        map_.insert(std::make_pair(entry->character(), entry));
    }
  
    BitField 
    CodeTable::code(int8_t character)
    {
        return map_[character]->code();
    }

    bool  
    CodeTable::character(const BitField & code, int8_t & ch) const
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
    operator << (std::ostream & os, const NodeData & cce)
    {
        os << cce.character_ << cce.frequency_;
        return os; 
    }

    const std::unordered_map<char, std::shared_ptr<NodeData>> & 
    CodeTable::map(void) const
    {
        return map_;
    }
}