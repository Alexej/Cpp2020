#include "../../include/DataStructure/HeaderInfo.hpp"

namespace Cress::DataStructure
{
    HeaderInfo::HeaderInfo(int32_t gho, int32_t cdlib)
    : globalHeaderOffset(gho),
      compressedDataLengthInBits(cdlib)
    {}
} 