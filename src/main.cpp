#include <iostream>
#include <string>
#include "./hello.hpp"
#include "i2b.hpp"
#include "VByte/vbyte.hpp"
#include "bitArray/bitArray.hpp"
#include "utils/utils.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  //if (argc != 4) {
  //  cout << "usage: " << argv[0] << "<lib> <func> <filename>\n";
  //  cout << "filename must end to '.OSbin'";
  //  exit(1);
  //}
  hello::message();

  //if (lib == "int2bin") { // INTEGER 2 BINARY

  //  if (func == "encode") iTob::encode(input_file);
  //  else if (func == "decode") iTob::decode(input_file);


  //} else if (lib == "vbyte") { // VBYTE

  //  if (func == "encode") vbyte::encode(input_file);
  //  else if (func == "decode") vbyte::decode(input_file);


  //} else {
  //  cout << "Nothing happened!\n";
  //}

  BitVector bv = BitVector(10);
  bv.print_array();
  bv.set(10, true);
  bv.print_array();
  bv.set(8, true);
  bv.print_array();


  return 0;
}
