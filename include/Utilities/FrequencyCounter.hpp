#ifndef H_FREQUENCYCOUNTER
#define H_FREQUENCYCOUNTER


#include <utility>
#include <list>
#include <vector>
#include <algorithm>
#include <stdint.h>


//[TOPIC](20) einfache Templates
namespace Cpp2020::Utilities
{
    template<
    typename T, // Element
    typename U  // Frequency
    >          
    std::vector<std::pair<T, U>> 
    FrequencyCounter(std::vector<T> list)
    {
        //[TOPIC](21) wichtige Container der C++-Standardbibliothek
        std::vector<std::pair<T, U>> ret;
        while(list.size() > 0)
        {
            T currentElement = list.front();
            U frequency = std::count(list.begin(), list.end(), currentElement);
            list.erase(std::remove(list.begin(), list.end(), currentElement), list.end()); //[TOPIC][3](24) Idiome: Erase-Remove
            ret.push_back({currentElement, frequency});
        }
        return ret;
    }
}

#endif // H_FREQUENCYCOUNTER