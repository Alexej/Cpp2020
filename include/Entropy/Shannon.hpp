#ifndef H_SHANNON
#define H_SHANNON

#include "../Utilities/FrequencyCounter.hpp"
#include "../FileHandling/FileIO.hpp"
#include <utility>
#include <math.h>
#include <iostream>

namespace Cress::Entropy
{
    class Shannon
    {
        public:
            explicit Shannon(const std::string & filePath);
            void calculateEntropy(void);
            void showEntropy(std::ostream & out) const;
            double logB2(double n);
        private:    
            FileHandling::FileIO io_;
            double entropy_ = 0.f;
            std::vector<int8_t> data_;
    };
}

#endif