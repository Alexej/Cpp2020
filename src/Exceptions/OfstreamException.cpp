#include "../../include/Exceptions/OfstreamException.hpp"

namespace Cress::Exceptions
{
    const char * OfstreamException::what () const throw ()
    {
        return "Error mapping file into memory!";
    }
}