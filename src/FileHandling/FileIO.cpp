#include "../../include/FileHandling/FileIO.hpp"
#include <iostream>

namespace Cress::FileHandling
{
    FileIO::FileIO(std::string filePath) 
    : filename_(filePath)
    {
        std::ifstream inputStream(filePath, std::ios::binary | std::ios::in);
        if(!inputStream.is_open())
            std::cout << "Error opening file" << std::endl;
            //throw

        inputStream.seekg(0, std::ios_base::end);
        std::streamsize size = inputStream.tellg();
        inputStream.seekg(0, std::ios::beg);

        dataVec.resize(size);
        inputStream.read((char*)dataVec.data(), size);
        inputStream.close();
    } 

    std::vector<int8_t> 
    FileIO::data(void) const
    {
        return dataVec; 
    }

    std::string 
    FileIO::filename(void) const
    {
        return filename_;
    }

    void 
    FileIO::writeFile(const std::unordered_map<char, std::shared_ptr<CCFEntry>> & map,
                           std::string filename, 
                           const BitVector & bv)
    {
        std::ofstream outputStream(filename + COMPRESSED_FILE_EXTENSION, std::ios::out | std::ios::binary);
        if(!outputStream.is_open()) 
            std::cout << "Error creating file" << std::endl;
            // throw
        outputStream << bv.bits() << " ";
        outputStream << map.size() << " ";
        for(auto el : map)
            outputStream << *el.second << " ";
        outputStream << "\n";
        outputStream.write((char*)bv.vector().data(), bv.size());
        outputStream.close();
    }

    void 
    FileIO::writeFile(std::string filename, std::vector<int8_t> compressedCode)
    {
        std::string newFileName = filename.substr(0,filename.size()-2) + DECOMPRESSED_FILE_EXTENSION;
        std::ofstream outputStream(newFileName, std::ios::out | std::ios::binary);
        if(!outputStream.is_open()) 
            std::cout << "Error creating file" << std::endl;
            // throw
        outputStream.write((char*)compressedCode.data(), compressedCode.size());
        outputStream.close();
    }
}  