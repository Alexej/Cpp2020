#ifndef H_FILENOTCOMPRESSEDEXCEPTION
#define H_FILENOTCOMPRESSEDEXCEPTION

#include <exception>

namespace Cpp2020::Exceptions
{
    class FileNotCompressedException : public std::exception
    {
        public:
            const char * what () const throw ();
    };
}

#endif // !H_FILENOTCOMPRESSEDEXCEPTION