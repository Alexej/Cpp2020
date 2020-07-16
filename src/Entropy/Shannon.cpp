#include "../../include/Entropy/Shannon.hpp"

namespace Cress::Entropy
{
    Shannon::Shannon(std::string filePath)
    : io_(filePath)
    {
        for(std::size_t i = 0; i < io_.size(); ++i)
            data_.push_back(*((int8_t*)io_.data() + i));
        calculateFrequency();
        calculateEntropy();
        showEntropy(std::cout);
    }
    
    double Shannon::logB2(double n)
    {
        return log(n) / log(2);
    }

    void Shannon::calculateFrequency(void)
    {
        charFreqVec_ =  Utilities::FrequencyCounter<int8_t, int32_t>(data_);
    }

    void Shannon::calculateEntropy(void)
    {
        int32_t size = io_.size();
        for(auto character : charFreqVec_)
        {
            double p = (static_cast<double>(character.second) / static_cast<double>(size));
#ifdef VERBOSE
            std::cout << "char: " << character.first << " Probability: " << p << " Frequency: "<< character.second << "/" << io.size() << std::endl;
#endif
            entropy_ += -(p * logB2(p)); 
        }
    }

    void Shannon::showEntropy(std::ostream & out) const
    {
        out << "The minimum average number of bits per symbol is: ";
        out << entropy_ << "\n";
    }
}