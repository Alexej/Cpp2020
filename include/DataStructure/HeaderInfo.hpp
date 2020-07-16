#ifndef H_HEADERINFO
#define H_HEADERINFO

#include <stdint.h>

namespace Cress::DataStructure
{
    class HeaderInfo
    {
        public:
            HeaderInfo() = default;
            HeaderInfo(int32_t gho, int32_t cdlib);
            int32_t globalHeaderOffset;
            int32_t compressedDataLengthInBits;
    };
}

#endif