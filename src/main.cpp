#ifndef TESTS

#include "../include/Application/Core.hpp"
#include "../include/Exceptions/FstatException.hpp"
#include "../include/Exceptions/MmapException.hpp"
#include "../include/Exceptions/OfstreamException.hpp"
#include "../include/Exceptions/OpenException.hpp"
#include "../include/Exceptions/FileNotCompressedException.hpp"

int main(int argc, char** argv)
{
    using namespace Cress::Application;
    Core core(argc, argv);
    try
    {
        core.work();    
    }
    catch(const FstatException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const MmapException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const OfstreamException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const OpenException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const FileNotCompressedException & e)
    {
        std::cout << e.what() << std::endl;
    }
}

#endif
