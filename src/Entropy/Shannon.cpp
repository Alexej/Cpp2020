#include "../../include/Entropy/Shannon.hpp"

namespace Cress::Entropy
{
    Shannon::Shannon(std::string filePath)
    : io(filePath)
    {
        for(auto& el : io.data())
            data.push_back(el);
        calculateFrequency();
        calculateEntropy();
        showEntropy();
    }
    
    double Shannon::logB2(double n)
    {
        return log(n) / log(2);
    }

    void Shannon::calculateFrequency(void)
    {
        while(data.size() > 0)
        {
            int8_t currentByte = data.front();
            int32_t frequency = std::count(data.begin(), data.end(), currentByte);
            data.remove(currentByte);
            charFreqVec.push_back(std::make_pair(currentByte, frequency));
        }
    }

    void Shannon::calculateEntropy(void)
    {
        int32_t size = io.data().size();
        for(auto character : charFreqVec)
        {
            double p = (static_cast<double>(character.second) / static_cast<double>(size));
#ifdef VERBOSE
            std::cout << "char: " << character.first << " Probability: " << p << " Frequency: "<< character.second << "/" << io.data().size() << std::endl;
#endif
            entropy += abs((p * logB2(p))); 
        }
    }

    void Shannon::showEntropy(void) const
    {
        printf("The minimum average number of bits per symbol is: %f bits per byte\n", entropy);
    }
}