#!/bin/sh

echo "Building huffman..."
bash build_tests.sh
./../bin/huffman_tests
echo "Cleaning up"
rm ../bin/*
rm *txt*
echo "Done"
