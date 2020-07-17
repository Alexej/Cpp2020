#ifndef H_OFSTREAMEXCEPTION
#define H_OFSTREAMEXCEPTION

#include <exception>

namespace Cpp2020::Exceptions
{
    class OfstreamException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_OFSTREAMEXCEPTION
