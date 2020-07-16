#ifndef H_ICOMPRESSION
#define H_ICOMPRESSION

namespace Cress::Interfaces
{
    class ICompression
    {   
        protected:
            virtual void compress() = 0;
            virtual void decompress() = 0;
    };
}

#endif // H_ICOMPRESSION