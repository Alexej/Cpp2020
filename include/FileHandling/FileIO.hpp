#ifndef H_FILEIO
#define H_FILEIO

#include "../DataStructure/CharacterCodeTable.hpp"
#include "../DataStructure/BitVector.hpp"
#include <vector>
#include <fstream>
 
namespace Cress::FileHandling
{
    using namespace Cress::DataStructure;
    class FileIO
    {
        public: 
            explicit FileIO(std::string fileName);
            std::string filename(void) const;
            std::vector<int8_t> data(void) const;
            void writeFile(const std::unordered_map<char, std::shared_ptr<CCFEntry>> & map, 
                           std::string filename, 
                           const BitVector & bv);
                           
            void writeFile(std::string filename, 
                           std::vector<int8_t> compressedCode);
        private:
            std::string filename_;
            std::vector<int8_t> dataVec;
    };
}

#endif // H_RWFile