#include "../../include/Exceptions/OpenException.hpp"

namespace Cpp2020::Exceptions
{
    const char * OpenException::what () const throw ()
    {
        return "File not Found!";
    }
}