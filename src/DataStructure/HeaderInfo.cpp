#include "../../include/DataStructure/HeaderInfo.hpp"

namespace Cpp2020::DataStructure
{
    HeaderInfo::HeaderInfo(int32_t gho, int32_t cdlib)
    : globalHeaderOffset_(gho),
      compressedDataLengthInBits_(cdlib)
    {}
}  