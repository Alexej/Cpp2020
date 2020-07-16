#include "../../include/Application/Core.hpp"

namespace Cress::Application
{
    Core::Core(int argc, char** argv)
    : argc_(argc),
      argv_(argv)
    {}

    void Core::showInfo(std::ostream & out) const
    {
        out << Banner::banner << std::endl;
    }

    void Core::work(void)
    {
        std::vector<std::string> arguments;
        for(int32_t i = 0; i < argc_; ++i)
            arguments.push_back(std::string(argv_[i]));

        if(argc_ < 2 || argc_ > 3)
            showInfo(std::cout);
        else
        {
            std::string flag = "";
            int32_t counter = 0;
            int32_t position = 0;
            for(auto arg : arguments)
            {
                if(arg.length() == 2)
                {    
                    flag = arg;
                    ++counter;
                    break;
                }
                ++position;
            }
            if(flag == "" || counter != 1)
                showInfo(std::cout);
            else
            {
                if(flag == HELP_FLAG)
                    showInfo(std::cout);
                else
                {
                    if(arguments.size() !=3 )
                        showInfo(std::cout);
                    else
                    {
                        std::string filename = (position == 1) ? std::string(arguments[2]) : std::string(arguments[1]);
                        if(flag == DECOMPRESSION_FLAG)
                        {
                            if(filename.substr(filename.length()-2, filename.length()) != COMPRESSED_FILE_EXTENSION)
                                throw Exceptions::FileNotCompressedException();
                                
                            Compression::Huffman h(filename, Compression::Mode::DECOMRESSION);   
                        }            
                        else if(flag == COMPRESSION_FLAG)
                            Compression::Huffman h(filename, Compression::Mode::COMPRESSION); 
                        else if(flag == ENTROPY_FLAG)
                            Entropy::Shannon s(filename);
                    }
                }
            }
        }
    }
}