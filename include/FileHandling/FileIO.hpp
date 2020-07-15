#ifndef H_FILEIO
#define H_FILEIO

#include "../DataStructure/CharacterCodeTable.hpp"
#include "../DataStructure/BitVector.hpp"
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

namespace Cress::FileHandling
{
    using namespace Cress::DataStructure;
    class FileIO
    {
        public: 
            explicit FileIO(std::string fileName);
            void openFile(void);
            void mapFile(void);
            void getFileStats(void);
            std::string filename(void) const;
            void * data(void) const;
            std::size_t size(void) const;

            
            void writeFile(const std::unordered_map<char, std::shared_ptr<CCFEntry>> & map, 
                           std::string filename, 
                           const BitVector & bv);
                           
            void writeFile(std::string filename, 
                           std::vector<int8_t> compressedCode);
        private:
            std::string filename_;
            int32_t fileHandle_;
            struct stat stat_;
            void * address_;
    };
}

#endif // H_RWFile
