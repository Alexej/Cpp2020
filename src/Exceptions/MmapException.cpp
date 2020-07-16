#include "../../include/Exceptions/MmapException.hpp"

namespace Cress::Exceptions
{
    const char * MmapException::what () const throw ()
    {
        return "Error mapping file into memory!";
    }
}