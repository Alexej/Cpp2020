#ifndef H_BITGETTERS
#define H_BITGETTERS

namespace Cpp2020::BitGetters
{
    const int mask8[8] = {1,2,4,8,16,32,64,128};
    const int mask16[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
    const int mask32[32] = {1,2,4,8,16,32,64,128,256,512,
                            1024,2048,4096,8192,16384,32768, 65536, 131072, 262144, 524288 // 12 getters missing, too lazy
                            
                            };

}
#endif // !H_BITGETTERS
