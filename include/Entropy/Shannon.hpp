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
            void showEntropy(void) const;
            void calculateFrequency(void);
            double logB2(double n);
        private:    
            FileIO io;
            double entropy = 0.f;
            std::list<int8_t> data;
            std::vector<std::pair<char, int32_t>> charFreqVec;
    };
}

#endif