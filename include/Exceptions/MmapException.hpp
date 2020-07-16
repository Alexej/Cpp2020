#ifndef H_MMAPEXCEPTION
#define H_MMAPEXCEPTION

#include <exception>

namespace Cress::Exceptions
{
    class MmapException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_MMAPEXCEPTION