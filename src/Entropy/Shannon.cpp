#include "../../include/Entropy/Shannon.hpp"

namespace Cpp2020::Entropy
{
    Shannon::Shannon(const std::string & filePath)
    : io_(filePath)
    {
        for(std::size_t i = 0; i < io_.size(); ++i)
            data_.push_back(*((int8_t*)io_.data() + i));
        calculateEntropy();
        showEntropy(std::cout);
    }
     
    double Shannon::logB2(double n)
    {
        return log(n) / log(2);
    }

    void Shannon::calculateEntropy(void)
    {
        int32_t size = io_.size();
        for(auto character : Utilities::FrequencyCounter<int8_t, int32_t>(data_))
        {
            double p = (static_cast<double>(character.second) / static_cast<double>(size));
#ifdef VERBOSE
            std::cout << "char: " << character.first << " Probability: " << p << " Frequency: "<< character.second << "/" << io.size() << std::endl;
#endif
            entropy_ += -(p * logB2(p)); 
        }
    }

    //[TOPIC](4) Daten: Darstellung*
    void Shannon::showEntropy(std::ostream & out) const
    {
        out << "The minimum average number of bits per symbol is: ";
        out << entropy_ << "\n";
    }
}