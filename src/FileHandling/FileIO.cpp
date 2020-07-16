#include "../../include/FileHandling/FileIO.hpp"
#include <iostream>

namespace Cress::FileHandling
{
    FileIO::FileIO(std::string fileName)
    : filename_(fileName)
    {
        openFile();
        getFileStats();
        mapFile();
    }

    void FileIO::openFile(void)
    {
        fileHandle_ = open(filename_.c_str(), O_RDONLY);
        if (fileHandle_ == -1)
            throw OpenException();
    }

    void FileIO::getFileStats(void)
    {
        if (fstat(fileHandle_, &stat_) == -1)
            throw FstatException();
    }


    void FileIO::mapFile(void)
    {
        address_ = mmap(NULL, stat_.st_size, PROT_READ, MAP_PRIVATE, fileHandle_, NULL);
        if (address_ == MAP_FAILED)
            throw MmapException();
    } 

    std::size_t FileIO::size(void) const
    {
        return stat_.st_size;
    }

    void * 
    FileIO::data(void) const 
    {
        return address_; 
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
            throw OfstreamException();
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
            throw OfstreamException();
        outputStream.write((char*)compressedCode.data(), compressedCode.size());
        outputStream.close();
    }
}