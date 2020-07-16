#ifndef H_SHANNON
#define H_SHANNON

#include "../FileHandling/FileIO.hpp"
#include <unordered_map>
#include <algorithm>
#include <list>
#include <utility>
#include <math.h>

namespace Cress::Entropy
{
    using namespace Cress::FileHandling;
    class Shannon
    {
        public:
            explicit Shannon(std::string filePath);
            void calculateEntropy(void);
            void showEntropy(std::ostream & out) const;
            void calculateFrequency(void);
            double logB2(double n);
        private:    
            FileIO io_;
            double entropy_ = 0.f;
            std::list<int8_t> data_;
            std::vector<std::pair<char, int32_t>> charFreqVec_;
    };
}

#endif