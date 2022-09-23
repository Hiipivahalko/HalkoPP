#!/bin/bash
echo "Started parallel runs"
date
echo "inputfile: $1"
echo "outputfile: $2"
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > $2
./build/halkoPP $1 raw 1000 < ./data/test_input1.txt >> $2 &
./build/halkoPP $1 raw 0100 < ./data/test_input1.txt >> $2 &
./build/halkoPP $1 raw 0010 < ./data/test_input1.txt >> $2 &
./build/halkoPP $1 raw 0001 < ./data/test_input1.txt >> $2 &

./build/halkoPP $1 raw 1000 < ./data/test_input2.txt >> $2 &
./build/halkoPP $1 raw 0100 < ./data/test_input2.txt >> $2 &
./build/halkoPP $1 raw 0010 < ./data/test_input2.txt >> $2 &
./build/halkoPP $1 raw 0001 < ./data/test_input2.txt >> $2 &


wait
./build/halkoPP $1 raw 1000 < ./data/test_input3.txt >> $2 &
./build/halkoPP $1 raw 0100 < ./data/test_input3.txt >> $2 &
./build/halkoPP $1 raw 0010 < ./data/test_input3.txt >> $2 &
./build/halkoPP $1 raw 0001 < ./data/test_input3.txt >> $2 &

./build/halkoPP $1 raw 1000 < ./data/test_input4.txt >> $2 &
./build/halkoPP $1 raw 0100 < ./data/test_input4.txt >> $2 &
./build/halkoPP $1 raw 0010 < ./data/test_input4.txt >> $2 &
./build/halkoPP $1 raw 0001 < ./data/test_input4.txt >> $2 &
wait
echo "all runs done"
