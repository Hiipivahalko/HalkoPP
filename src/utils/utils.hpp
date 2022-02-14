#include <vector>
#include <iostream>
#include <string>
#include <fstream>

namespace utils {
  void print_uInt_vector(const std::vector<u_int32_t> &v, const std::string s);
  void copy_n_blocks(const char *input_file, const std::string &output_file, const u_int64_t &n);
}
