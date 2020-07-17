#ifndef H_APPLICATION
#define H_APPLICATION

#include "../Banner.hpp"
#include "../Exceptions/FileNotCompressedException.hpp"
#include "../Compression/Huffman.hpp"
#include "../Entropy/Shannon.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <exception>

namespace Cpp2020::Application
{
    class Core
    {
        public:
            Core(int argc, char** argv);
            void showInfo(std::ostream & out) const;
            void work(void);
        private:
            int32_t argc_;
            char** argv_;
    };
}
 
#endif // H_APPLICATION