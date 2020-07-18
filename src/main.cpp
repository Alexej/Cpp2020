#ifndef TESTS

#include "../include/Application/Core.hpp"
#include "../include/Exceptions/FstatException.hpp"
#include "../include/Exceptions/MmapException.hpp"
#include "../include/Exceptions/OfstreamException.hpp"
#include "../include/Exceptions/OpenException.hpp"
#include "../include/Exceptions/FileNotCompressedException.hpp"

//https://stackoverflow.com/questions/32257840/properly-terminating-program-using-exceptions

/*
[TOPIC](25) Best Practices: 0 bis 33
[TOPIC](26) häufige Fehlerquellen
*/

int main(int argc, char** argv)
{
    Cpp2020::Application::Core core(argc, argv);
    try 
    {
        core.work();    
    }
    catch(const Cpp2020::Exceptions::FstatException & e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(const Cpp2020::Exceptions::MmapException & e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(const Cpp2020::Exceptions::OfstreamException & e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(const Cpp2020::Exceptions::OpenException & e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(const Cpp2020::Exceptions::FileNotCompressedException & e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

#endif
