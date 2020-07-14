#!/bin/sh

echo "Building cress..."
bash build_tests.sh
./../bin/cress_tests
echo "Cleaning up"
rm ../bin/*
rm *txt*
echo "Done"
