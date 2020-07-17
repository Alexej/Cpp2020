#include "../../include/Exceptions/FileNotCompressedException.hpp"

namespace Cpp2020::Exceptions
{
    const char * FileNotCompressedException::what () const throw ()
    {
        return "Please provide only .c files for decompression!";
    }
}