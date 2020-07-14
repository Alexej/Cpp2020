#ifndef H_APPLICATION
#define H_APPLICATION

#include "../Compression/HuffmanCompression.hpp"
#include "../Entropy/Shannon.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <exception>

namespace Cress::Application
{
    using namespace Cress::Compression;
    using namespace Cress::Entropy;
    class Core
    {
        public:
            Core(int argc, char** argv);
            void showInfo(void) const;
            void work(void);
        private:
            int32_t argc_;
            char** argv_;
    };
}
 
#endif // H_APPLICATION