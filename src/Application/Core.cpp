#include "../../include/Application/Core.hpp"

namespace Cress::Application
{
    Core::Core(int argc, char** argv)
    : argc_(argc),
      argv_(argv)
    {}

    void Core::showInfo(void) const
    {
        std::cout << std::endl;
        std::cout << "        ▄████████    ▄████████    ▄████████    ▄████████    ▄████████  " << std::endl;
        std::cout << "        ███    ███   ███    ███   ███    ███   ███    ███   ███    ███ " << std::endl;
        std::cout << "        ███    █▀    ███    ███   ███    █▀    ███    █▀    ███    █▀  " << std::endl;
        std::cout << "        ███         ▄███▄▄▄▄██▀  ▄███▄▄▄       ███          ███        " << std::endl;
        std::cout << "        ███        ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     ▀███████████ ▀███████████ " << std::endl;
        std::cout << "        ███    █▄  ▀███████████   ███    █▄           ███          ███ " << std::endl;
        std::cout << "        ███    ███   ███    ███   ███    ███    ▄█    ███    ▄█    ███ " << std::endl;
        std::cout << "        ████████▀    ███    ███   ██████████  ▄████████▀   ▄████████▀  " << std::endl;
        std::cout << "                     ███    ███                                        " << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "          Usage:" << std::endl;
        std::cout << "              ./huffman -c <Filename> : Compress" << std::endl;
        std::cout << "              ./huffman -d <Filename> : Decompress" << std::endl;
        std::cout << "              ./huffman -e <Filename> : Entropy" << std::endl;
        std::cout << "              ./huffman -h            : Info" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void Core::work(void)
    {
        const std::string helpFlag = "-h";
        const std::string compressionFlag = "-c";
        const std::string decompressionFlag = "-d";
        const std::string entropyFlag = "-e";

        std::vector<std::string> arguments;
        for(int32_t i = 0; i < argc_; ++i)
            arguments.push_back(std::string(argv_[i]));

        if(argc_ < 2 || argc_ > 3)
            showInfo();
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
                showInfo();
            else
            {
                if(flag == helpFlag)
                    showInfo();
                else
                {
                    if(arguments.size() !=3 )
                        showInfo();
                    else
                    {
                        std::string filename = (position == 1) ? std::string(arguments[2]) : std::string(arguments[1]);
                        if(flag == decompressionFlag)
                        {
                            if(filename.substr(filename.length()-2, filename.length()) != COMPRESSED_FILE_EXTENSION)
                            {
                                std::cout << "Please provide only .c files for decompression!" << std::endl;
                                exit(EXIT_FAILURE);

                            }
                            HuffmanCompression h(filename, Mode::DECOMRESSION);   
                        }            
                        else if(flag == compressionFlag)
                            HuffmanCompression h(filename, Mode::COMPRESSION); 
                        else if(flag == entropyFlag)
                            Shannon s(filename);
                    }
                }
            }
        }
    }
}