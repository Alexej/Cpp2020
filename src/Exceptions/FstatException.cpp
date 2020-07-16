#include "../../include/Exceptions/FstatException.hpp"

namespace Cress::Exceptions
{
    const char * FstatException::what () const throw ()
    {
        return "Error while obtaining Stats!";
    }
}