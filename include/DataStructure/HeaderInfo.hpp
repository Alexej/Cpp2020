#ifndef H_HEADERINFO
#define H_HEADERINFO

#include <stdint.h>

namespace Cpp2020::DataStructure
{
    class HeaderInfo
    {
        public:
            HeaderInfo() = default;
            HeaderInfo(int32_t gho, int32_t cdlib);
            int32_t globalHeaderOffset_;
            int32_t compressedDataLengthInBits_;
    };
}

#endif