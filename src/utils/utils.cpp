#include "utils.hpp"

namespace utils {
  void print_uInt_vector(const std::vector<u_int32_t> &v, const std::string s) {
    for (u_int32_t i = 0; i < v.size(); i++) {
      if (s == "row") std::cout << v[i] << " ";
      else if (s == "col") std::cout << v[i] << "\n";
    }
    if (s == "row") std::cout << "\n";
  }
}