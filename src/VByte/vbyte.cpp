export module vbyte;

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef long long ll;

// VByte encode 64-bit integer
export vector<int> encodeInteger(ll x) {
  vector<int> seq;
  while (true) {
    int r = x % 128;
    if (x < 128) {
      r += 128;
      seq.push_back(r);
      //output_stream.write((char *)&r, 1);
      break;
    }
    seq.push_back(r);
    //output_stream.write((char *)&r, 1);
    x /= 128;
  }
  return seq;
}

export void encodeVByte(string input_file) {
  string output_file = input_file + ".vb";
  ifstream input_stream(input_file, ios::binary);
  ofstream output_stream(output_file, ios::binary);

  // read input file and encode integers from the file
  if (input_stream.is_open()) {
    ll x;
    while (input_stream.read((char *)&x, sizeof(x))) {
      vector<int> comp_seq = encodeInteger(x);
      for(int i = 0; i < comp_seq.size(); i++) {
        output_stream.write((char *)&comp_seq[i], 1);
      }
    }
  } else cout << "could not open the file\n";
  out

  input_stream.close();
  output_stream.close();
}