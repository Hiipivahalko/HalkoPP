#ifndef _BITARRAY_HPP_
#define _BITARRAY_HPP_

#include <iostream>
#include <algorithm>


class BitVector {
  public:
    uint64_t *arr;
    uint64_t last_bit;
    uint64_t arr_length;
    uint32_t block_length;

    BitVector(const uint64_t n);
    ~BitVector();

    int get(const uint64_t i) const;
    // set i-th bit value to 1 or 0
    void set(const uint64_t i, bool c);
    // printing bit array values. Each block is printed its own line.
    // Block bits are speareted with space every 8 bits.
    void print_array();

    uint32_t rank1(uint32_t i); // number of ones <= i
    uint32_t rank0(uint32_t i); // number of zeros <= i

    uint32_t select1(uint32_t); // index of (i-1)th one
    uint32_t select0(uint32_t); // index of (i-1)th zero
};

#endif
