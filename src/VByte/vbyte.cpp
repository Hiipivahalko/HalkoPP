#include "./vbyte.hpp"
#include "../utils/utils.hpp"

typedef u_int64_t u_ll;

namespace vbyte {
  // VByte encode 64-bit integer
  std::vector<u_int32_t> encodeInteger(u_ll x) {
    std::vector<u_int32_t> seq;
    while (true) {
      u_int32_t r = x % 128;
      if (x < 128) {
        r += 128;
        seq.push_back(r);
        // output_stream.write((char *)&r, 1);
        break;
      }
      seq.push_back(r);
      // output_stream.write((char *)&r, 1);
      x /= 128;
    }
    return seq;
  }

  // encode inputfile integers to vbyte encoding
  void encode(std::string input_file) {
    std::string output_file = input_file + ".vb";
    std::ifstream input_stream(input_file, std::ios::binary);
    std::ofstream output_stream(output_file, std::ios::binary);

    // read input file and encode integers from the file
    if (input_stream.is_open()) {
      u_ll x;
      //std::cout << sizeof(x) << "here\n";
      while (input_stream.read((char *)&x, sizeof(x))) {
        //std::cout << x << std::endl;
        std::vector<u_int32_t> comp_seq = encodeInteger(x);
        //utils::print_uInt_vector(comp_seq, "row");
        for (unsigned int i = 0; i < comp_seq.size(); i++) {
          output_stream.write((char *)&comp_seq[i], 1);
        }
      }
    } else std::cout << "could not open the file\n";

    input_stream.close();
    output_stream.close();
  }

  // compose vbyte parts to one integer
  u_ll composeBytes(const std::vector<u_int32_t> &vbytes) {
    u_ll result = 0;
    for (int32_t i = (int) vbytes.size()-1; i >= 0; i--) {
      result += vbytes[i];
      if (i != 0) result *= 128;
    }
    return result;
  }

  // decompose vbyte encoded integers to normal form
  void decode(std::string input_file) {
    std::string output_file = input_file + ".dec";
    std::ifstream input_stream(input_file, std::ios::binary);
    std::ofstream output_stream(output_file, std::ios::binary);
    
    if (input_stream.is_open()) { // check that we can read file 
      // reading bytes from inputfile and decoding VBytes back to normal format into outputfile "<outputfile>.vb.dec"
      int32_t x;
      std::vector<u_int32_t> v;
      u_ll decomp_int = 0;
      char c;
      while (input_stream.read(&c, 1)) {
        x = c;
        if (x < 0) x = (128+x) + 128;

        // if x is greater than 128 we know that we have all integer to decode original 64-bit integer
        if (x >= 128) {
          v.push_back(x-128);
          decomp_int = composeBytes(v);
          output_stream.write((char *) &decomp_int, sizeof(decomp_int));
          v.clear();
        } else v.push_back(x);
        
      }
    } else std::cout << "could not open the file\n";

    input_stream.close();
    output_stream.close();
  }


} // namespace vbyte