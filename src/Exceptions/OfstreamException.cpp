#include "../../include/Exceptions/OfstreamException.hpp"

namespace Cpp2020::Exceptions
{
    const char * OfstreamException::what () const throw ()
    {
        return "Error mapping file into memory!";
    }
}