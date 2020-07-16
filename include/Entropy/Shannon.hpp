#ifndef H_SHANNON
#define H_SHANNON

#include "../Utilities/FrequencyCounter.hpp"
#include "../FileHandling/FileIO.hpp"
#include <unordered_map>
#include <algorithm>
#include <list>
#include <utility>
#include <math.h>
#include <iostream>

namespace Cress::Entropy
{
    class Shannon
    {
        public:
            explicit Shannon(std::string filePath);
            void calculateEntropy(void);
            void showEntropy(std::ostream & out) const;
            void calculateFrequency(void);
            double logB2(double n);
        private:    
            FileHandling::FileIO io_;
            double entropy_ = 0.f;
            std::list<int8_t> data_;
            std::vector<std::pair<int8_t, int32_t>> charFreqVec_;
    };
}

#endif