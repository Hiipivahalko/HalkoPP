#include <vector>
#include <iostream>
#include <fstream>

namespace vbyte {
  std::vector<u_int32_t> encodeInteger(u_int64_t x);
  u_int64_t composeBytes(const std::vector<u_int32_t> &vbytes);
  void encode(std::string input_file);
  void decode(std::string input_file);
}