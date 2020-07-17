#ifndef H_BANNER
#define H_BANNER

#include <string>

namespace Cpp2020::Banner
{
    const std::string banner =  R"(
         _  _ _   _ ___ ___ __  __   _   _  _ 
        | || | | | | __| __|  \/  | /_\ | \| |
        | __ | |_| | _|| _|| |\/| |/ _ \| .` |
        |_||_|\___/|_| |_| |_|  |_/_/ \_\_|\_|
        
        Usage:
            ./huffman -c <Filename> : Compress the file
            ./huffman -d <Filename> : Decompress the file
            ./huffman -e <Filename> : Calculate the Shannon-Entropy
            ./huffman -h            : Info
            
    )";
}

#endif // H_BANNER