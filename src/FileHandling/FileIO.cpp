#include "../../include/FileHandling/FileIO.hpp"
#include <iostream>

namespace Cress::FileHandling
{
    FileIO::FileIO(const std::string & fileName)
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
            throw Exceptions::OpenException();
    }

    void FileIO::getFileStats(void)
    {
        if (fstat(fileHandle_, &stat_) == -1)
            throw Exceptions::FstatException();
    }


    void FileIO::mapFile(void)
    {
        address_ = mmap(NULL, stat_.st_size, PROT_READ, MAP_PRIVATE, fileHandle_, 0);
        if (address_ == MAP_FAILED)
            throw Exceptions::MmapException();
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
    FileIO::writeFile(const std::unordered_map<char, 
                      std::shared_ptr<DataStructure::NodeData>> & map,
                      const std::string & filename, 
                      const DataStructure::BitVector & bv)
    {
        std::ofstream outputStream(filename + COMPRESSED_FILE_EXTENSION, std::ios::out | std::ios::binary);
        if(!outputStream.is_open()) 
            throw Exceptions::OfstreamException();
        outputStream << bv.bits() << " ";
        outputStream << map.size() << " ";
        for(auto el : map)
            outputStream << *el.second << " ";
        outputStream << "\n";
        outputStream.write((char*)bv.vector().data(), bv.size());
        outputStream.close();
    }

    void 
    FileIO::writeFile(const std::string & filename, 
                      const std::vector<int8_t> & compressedCode)
    {
        std::ofstream outputStream(filename.substr(0,filename.size()-2) + DECOMPRESSED_FILE_EXTENSION,
                                   std::ios::out | std::ios::binary);
        if(!outputStream.is_open()) 
            throw Exceptions::OfstreamException();
        outputStream.write((char*)compressedCode.data(), compressedCode.size());
        outputStream.close();
    }
}