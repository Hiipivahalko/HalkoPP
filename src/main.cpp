#include <iostream>
#include <string>
#include "./hello.hpp"
#include "i2b.hpp"
#include "VByte/vbyte.hpp"
#include "bitArray/bitVector.hpp"
#include "utils/utils.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  hello::message();

  string output_file = "data/small_sample2.dat";
  iTob::encode(output_file);


  return 0;
}
