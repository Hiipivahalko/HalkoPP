#!/bin/bash

cmake -S . -B build_test
cmake --build build_test
cd build_test && ctest && cd .. || cd ..
