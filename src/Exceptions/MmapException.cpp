#include "../../include/Exceptions/MmapException.hpp"

namespace Cpp2020::Exceptions
{
    const char * MmapException::what () const throw ()
    {
        return "Error mapping file into memory!";
    }
}