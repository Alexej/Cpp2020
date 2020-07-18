#!/bin/sh

# [TOPIC](3) Toolchain: Fehler und Warnings*
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
clang++ $(find ../ -name '*.cpp' ! -path '../tests/*' ) -o ../bin/huffman  ${CPPFLAGS} #Make default binary
