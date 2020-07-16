#!/bin/sh
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
LDFLAGS="-fsanitize=address"
clang++  $(find ../ -name '*.cpp') -o ../bin/huffman_tests  ${CPPFLAGS} ${LDFLAGS} -DTESTS  