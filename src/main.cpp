#ifndef TESTS

#include "../include/Application/Core.hpp"
#include "../include/Exceptions/FstatException.hpp"
#include "../include/Exceptions/MmapException.hpp"
#include "../include/Exceptions/OfstreamException.hpp"
#include "../include/Exceptions/OpenException.hpp"
#include "../include/Exceptions/FileNotCompressedException.hpp"

int main(int argc, char** argv)
{
    Cress::Application::Core core(argc, argv);
    try 
    {
        core.work();    
    }
    catch(const Cress::Exceptions::FstatException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const Cress::Exceptions::MmapException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const Cress::Exceptions::OfstreamException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const Cress::Exceptions::OpenException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const Cress::Exceptions::FileNotCompressedException & e)
    {
        std::cout << e.what() << std::endl;
    }
}

#endif
