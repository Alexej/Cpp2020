#ifndef H_OFSTREAMEXCEPTION
#define H_OFSTREAMEXCEPTION

#include <exception>

namespace Cress::Exceptions
{
    class OfstreamException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_OFSTREAMEXCEPTION
