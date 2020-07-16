#include "../../include/Exceptions/FileNotCompressedException.hpp"

namespace Cress::Exceptions
{
    const char * FileNotCompressedException::what () const throw ()
    {
        return "Please provide only .c files for decompression!";
    }
}