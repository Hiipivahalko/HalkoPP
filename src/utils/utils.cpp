#include "utils.hpp"

using namespace std;

void read_input_file2(const char *input_file, vector<uint64_t> &seq_ref, uint64_t nn) {
  FILE *fp = fopen(input_file, "r");
  uint64_t u, n;

  fseek(fp, 0, SEEK_END);
  n = ftell(fp) / sizeof(uint64_t);
  fseek(fp, 0, SEEK_SET);

  cout << ">> Input file lenght: " << n << endl;

  for (uint64_t i = 0; i < nn; i++) {
    fread(&u, sizeof(uint64_t), 1, fp);
    seq_ref.push_back(u);
  }
  fclose(fp);  // closing inputfile
}

namespace utils {
void print_uInt_vector(const std::vector<u_int32_t> &v, const std::string s) {
  for (u_int32_t i = 0; i < v.size(); i++) {
    if (s == "row")
      std::cout << v[i] << " ";
    else if (s == "col")
      std::cout << v[i] << "\n";
  }
  if (s == "row") std::cout << "\n";
}

// read n 8-byte blocks and write those to output file
void copy_n_blocks(const char *input_file, const string &output_file, const u_int64_t &n) {
  ifstream inf(input_file, ios::binary);
  ofstream ofs(output_file, ios::binary);
  vector<u_int64_t> v;

  read_input_file2(input_file, v, n);
  u_int64_t *t;
  for (u_int64_t i = 0; i < n; i++) {
    t = &v[i];
    ofs.write((char *)t, sizeof(u_int64_t));
    //cout << v[i] << endl;
  }
  ofs.close();
}

string current_time2str() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string curr_time = to_string(1900 + ltm->tm_year) + "_" + to_string(1 + ltm->tm_mon) + "_" + to_string(ltm->tm_mday) +
        "_" + to_string(ltm->tm_hour) + to_string(ltm->tm_min) + to_string(ltm->tm_sec);
    return curr_time;
}

}  // namespace utils
