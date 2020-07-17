#ifndef H_MMAPEXCEPTION
#define H_MMAPEXCEPTION

#include <exception>

namespace Cpp2020::Exceptions
{
    class MmapException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_MMAPEXCEPTION