#ifndef H_FREQUENCYCOUNTER
#define H_FREQUENCYCOUNTER


#include <utility>
#include <list>
#include <vector>
#include <algorithm>
#include <stdint.h>

namespace Cpp2020::Utilities
{
    template<
    typename T, // Element
    typename U  // Frequency
    >          
    std::vector<std::pair<T, U>> 
    FrequencyCounter(std::vector<T> list)
    {
        std::vector<std::pair<T, U>> ret;
        while(list.size() > 0)
        {
            T currentElement = list.front();
            U frequency = std::count(list.begin(), list.end(), currentElement);
            list.erase(std::remove(list.begin(), list.end(), currentElement), list.end()); // Very slow
            ret.push_back({currentElement, frequency});
        }
        return ret;
    }
}

#endif // H_FREQUENCYCOUNTER