#ifndef H_FILEIO
#define H_FILEIO

#include "../Exceptions/FstatException.hpp"
#include "../Exceptions/MmapException.hpp"
#include "../Exceptions/OfstreamException.hpp"
#include "../Exceptions/OpenException.hpp"
#include "../DataStructure/CodeTable.hpp"
#include "../DataStructure/BitVector.hpp"
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

namespace Cpp2020::FileHandling
{
    class FileIO
    {
        public: 
            explicit FileIO(const std::string & fileName);
            void openFile(void);
            void mapFile(void);
            void getFileStats(void);
            std::string filename(void) const;
            void * data(void) const;
            std::size_t size(void) const;
            
            void writeFile(const std::unordered_map<char, 
                           std::shared_ptr<DataStructure::NodeData>> & map, 
                           const std::string & filename, 
                           const DataStructure::BitVector & bv);
                           
            void writeFile(const std::string & filename, 
                           const std::vector<int8_t> & compressedCode);

        private:
            std::string filename_;
            int32_t fileHandle_;
            struct stat stat_;
            void * address_;
    };
}

#endif // H_RWFile
