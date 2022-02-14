#include <iostream>
#include <string>
#include "./hello.hpp"
#include "i2b.hpp"
#include "VByte/vbyte.hpp"
#include "utils/utils.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cout << "usage: " << argv[0] << "<lib> <func> <filename>\n";
    cout << "filename must end to '.OSbin'";
    exit(1);
  }
  hello::message();
  string lib = (string) argv[1];
  string func = (string) argv[2];
  string input_file = (string) argv[3];

  if (lib == "int2bin") { // INTEGER 2 BINARY

    if (func == "encode") iTob::encode(input_file);
    else if (func == "decode") iTob::decode(input_file); 


  } else if (lib == "vbyte") { // VBYTE

    if (func == "encode") vbyte::encode(input_file);
    else if (func == "decode") vbyte::decode(input_file); 


  } else if (lib == "test") {
    utils::copy_n_blocks(argv[3], "./data/output.dat", 100000);
  } else {
    cout << "Nothing happened!\n";
  }
  
  return 0;
}