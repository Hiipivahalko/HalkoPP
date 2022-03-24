#include "bitArray.hpp"

using namespace std;

constexpr int BITS_IN_LONGLONG = 64;
constexpr u_int64_t I = 1;

BitArray::BitArray(const uint64_t n) {
      block_length = 64;
      arr_length = (n / block_length) + 1;
      arr = new uint64_t[arr_length]{0};
      last_bit = n;
}


int BitArray::get(const uint64_t i) const {
  return (arr[ ((i-1) / block_length) ] >> ((i-1) % block_length)) & I;
}

// set i-th bit value to 1 or 0
void BitArray::set(const uint64_t i, bool c) {
  if (c == 1) arr[ ((i-1)/ block_length) ] |= ( I << ( (i-1) % block_length ) ); // to value 1
  else arr[ (i/ block_length) ] &= ~( I << ( (i-1) % block_length ) ); // to value 0
}

// printing bit array values. Each block is printed its own line.
// printing is done from most significant bit to last significat
// Block bits are speareted with space every 8 bits.
void BitArray::print_array() {
  for (uint64_t i = last_bit; i > 0; i--) {
    if (i % 64 == 0) cout << "\n";
    if (i % 8 == 0) cout << " ";
    cout << get(i);
  }
  cout << "\n";
}

