#include "./hello.hpp"

namespace hello {
  void message() {
    std::cerr << "Hello World\n";
  }

  int power2(int x ){
    return x*x;
  }
}
