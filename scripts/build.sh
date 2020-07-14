#!/bin/sh
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
clang++ $(find ../ -name '*.cpp' ! -path '../tests/*' ) -o ../bin/cress  ${CPPFLAGS} #Make default binary
