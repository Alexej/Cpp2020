#ifndef H_OPENEXCEPTION
#define H_OPENEXCEPTION

#include <exception>

namespace Cpp2020::Exceptions
{ 
    class OpenException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_OPENEXCEPTION