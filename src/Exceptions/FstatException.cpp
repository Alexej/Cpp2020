#include "../../include/Exceptions/FstatException.hpp"

namespace Cpp2020::Exceptions
{
    const char * FstatException::what () const throw ()
    {
        return "Error while obtaining Stats!";
    }
}