#ifndef H_ICOMPRESSION
#define H_ICOMPRESSION

namespace Cpp2020::Interface
{
    class ICompression
    {   
        protected:
            //[TOPIC](15) Object Orientation: virtual methods
            virtual void compress() = 0;
            virtual void decompress() = 0;
    };
}

#endif // H_ICOMPRESSION