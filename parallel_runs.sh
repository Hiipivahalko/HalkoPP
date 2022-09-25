#!/bin/bash
trap "exit" INT TERM ERR
trap "kill 0" EXIT
if [ $# -lt 3 ];then
    echo "usage <postings_file> <prefix_name-U,O,M-vec> <output_csv_perfix>"
    exit 1
fi
echo "Started parallel runs"
echo "$3_div2.csv"
date
# div2
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > "$3_div2.csv"
./build/halkoPP $1 raw 1000 $2 div2 < ./data/test_input1.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 1000 $2 div2 < ./data/test_input2.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 1000 $2 div2 < ./data/test_input3.txt >> "$3_div2.csv" &


./build/halkoPP $1 raw 0100 $2 div2 < ./data/test_input1.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0100 $2 div2 < ./data/test_input2.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0100 $2 div2 < ./data/test_input3.txt >> "$3_div2.csv" &

./build/halkoPP $1 raw 0010 $2 div2 < ./data/test_input1.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0010 $2 div2 < ./data/test_input2.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0010 $2 div2 < ./data/test_input3.txt >> "$3_div2.csv" &

./build/halkoPP $1 raw 0001 $2 div2 < ./data/test_input1.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0001 $2 div2 < ./data/test_input2.txt >> "$3_div2.csv" &
./build/halkoPP $1 raw 0001 $2 div2 < ./data/test_input3.txt >> "$3_div2.csv" &
wait

# div4
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > "$3_div4.csv"
./build/halkoPP $1 raw 1000 $2 div4 < ./data/test_input1.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 1000 $2 div4 < ./data/test_input2.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 1000 $2 div4 < ./data/test_input3.txt >> "$3_div4.csv" &

./build/halkoPP $1 raw 0100 $2 div4 < ./data/test_input1.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0100 $2 div4 < ./data/test_input2.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0100 $2 div4 < ./data/test_input3.txt >> "$3_div4.csv" &

./build/halkoPP $1 raw 0010 $2 div4 < ./data/test_input1.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0010 $2 div4 < ./data/test_input2.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0010 $2 div4 < ./data/test_input3.txt >> "$3_div4.csv" &

./build/halkoPP $1 raw 0001 $2 div4 < ./data/test_input1.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0001 $2 div4 < ./data/test_input2.txt >> "$3_div4.csv" &
./build/halkoPP $1 raw 0001 $2 div4 < ./data/test_input3.txt >> "$3_div4.csv" &
wait

# div8
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > "$3_div8.csv"
./build/halkoPP $1 raw 1000 $2 div8 < ./data/test_input1.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 1000 $2 div8 < ./data/test_input2.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 1000 $2 div8 < ./data/test_input3.txt >> "$3_div8.csv" &

./build/halkoPP $1 raw 0100 $2 div8 < ./data/test_input1.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0100 $2 div8 < ./data/test_input2.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0100 $2 div8 < ./data/test_input3.txt >> "$3_div8.csv" &

./build/halkoPP $1 raw 0010 $2 div8 < ./data/test_input1.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0010 $2 div8 < ./data/test_input2.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0010 $2 div8 < ./data/test_input3.txt >> "$3_div8.csv" &

./build/halkoPP $1 raw 0001 $2 div8 < ./data/test_input1.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0001 $2 div8 < ./data/test_input2.txt >> "$3_div8.csv" &
./build/halkoPP $1 raw 0001 $2 div8 < ./data/test_input3.txt >> "$3_div8.csv" &
wait

# avg_run_length
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > "$3_avg_rle.csv"
./build/halkoPP $1 raw 1000 $2 avg_rle < ./data/test_input1.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 1000 $2 avg_rle < ./data/test_input2.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 1000 $2 avg_rle < ./data/test_input3.txt >> "$3_avg_rle.csv" &

./build/halkoPP $1 raw 0100 $2 avg_rle < ./data/test_input1.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0100 $2 avg_rle < ./data/test_input2.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0100 $2 avg_rle < ./data/test_input3.txt >> "$3_avg_rle.csv" &

./build/halkoPP $1 raw 0010 $2 avg_rle < ./data/test_input1.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0010 $2 avg_rle < ./data/test_input2.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0010 $2 avg_rle < ./data/test_input3.txt >> "$3_avg_rle.csv" &

./build/halkoPP $1 raw 0001 $2 avg_rle < ./data/test_input1.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0001 $2 avg_rle < ./data/test_input2.txt >> "$3_avg_rle.csv" &
./build/halkoPP $1 raw 0001 $2 avg_rle < ./data/test_input3.txt >> "$3_avg_rle.csv" &
wait

# median_run_length
echo "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)" > "$3_med_rle.csv"
./build/halkoPP $1 raw 1000 $2 med_rle < ./data/test_input1.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 1000 $2 med_rle < ./data/test_input2.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 1000 $2 med_rle < ./data/test_input3.txt >> "$3_med_rle.csv" &

./build/halkoPP $1 raw 0100 $2 med_rle < ./data/test_input1.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0100 $2 med_rle < ./data/test_input2.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0100 $2 med_rle < ./data/test_input3.txt >> "$3_med_rle.csv" &

./build/halkoPP $1 raw 0010 $2 med_rle < ./data/test_input1.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0010 $2 med_rle < ./data/test_input2.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0010 $2 med_rle < ./data/test_input3.txt >> "$3_med_rle.csv" &

./build/halkoPP $1 raw 0001 $2 med_rle < ./data/test_input1.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0001 $2 med_rle < ./data/test_input2.txt >> "$3_med_rle.csv" &
./build/halkoPP $1 raw 0001 $2 med_rle < ./data/test_input3.txt >> "$3_med_rle.csv" &
echo "all runs done"
