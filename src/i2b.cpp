#include "./i2b.hpp"

typedef u_int64_t u_ll;

namespace iTob {
  // encoding positive integers to binary format
  void encode(std::string &outputFile) {
    std::ofstream outf(outputFile, std::ios::binary);
    u_ll *t;
    u_ll val = 1;
    t = &val;
    std::cout << "give input integers (zero ends):\n";
    while (true) {
      std::cin >> val;
      if (*t == 0) break;
      outf.write((char *)t, sizeof(u_ll));
    }
    outf.close();
    return;
  }

  // decoding binary file that contains positive integers
  void decode(std::string &input_file) {
    unsigned int n = input_file.size();
    
    if ( ".OSbin" != input_file.substr(n-6,n) && ".vb.dec" != input_file.substr(n-7,n) ) {
      std::cerr << "File extension not correct\n";
      exit(1);
    }
    std::ifstream inf(input_file, std::ios::binary);
    if (inf.is_open()) {
      u_ll x;
      while(inf.read((char *) &x, 8)) {
        std::cout << x << "\n";
      }
    } else {
      std::cerr << "could not open the file: " << input_file << "\n";
      return;
    }
    inf.close();
  }
} // namespace iTob