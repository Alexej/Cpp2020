#ifndef H_FSTATEXCEPTION
#define H_FSTATEXCEPTION

#include <exception>

namespace Cpp2020::Exceptions
{
    class FstatException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_FSTATEXCEPTION