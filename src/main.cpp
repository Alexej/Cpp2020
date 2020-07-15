#ifndef TESTS
#include "../include/Application/Core.hpp"


/*
[TOPIC](1) Toolchain: Komponenten
Editor // VSCODE
Preprocessor (Präprozessor)
Compiler
Assembler
Linker (Binder)
Debugger // VSCODE + GDB
*/

/*
   [TOPIC](25) Best Practices: 0 bis 33 // Es wurden die meisten Sachen eingehalten.
   [TOPIC](26) häufige Fehlerquellen

   Ich habe versucht das Meiste umzusetzen, allerdings konnte ich aufgrund meiner Architektur nicht alles Practices 
   und Fehlerquellen berücksichtigen.
*/

/*
[TOPIC](24) Idiome*
Folgende C++ Idiome wurden verwendet:
    OOP
    Smart-Pointers
    Lambdas
*/

int main(int argc, char** argv)
{
    using namespace Cress::Application;
    Core core(argc, argv);
    core.work();
}

#endif
