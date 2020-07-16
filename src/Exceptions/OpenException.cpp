#include "../../include/Exceptions/OpenException.hpp"

namespace Cress::Exceptions
{
    const char * OpenException::what () const throw ()
    {
        return "File not Found!";
    }
}