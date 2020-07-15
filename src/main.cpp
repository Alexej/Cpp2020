#ifndef TESTS
#include "../include/Application/Core.hpp"

int main(int argc, char** argv)
{
    using namespace Cress::Application;
    Core core(argc, argv);
    core.work();
}

#endif
