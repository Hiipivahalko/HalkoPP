#include <iostream>
#include <string>
#include "./hello.hpp"
#include "i2b.hpp"
#include "VByte/vbyte.hpp"
#include "bitArray/bitVector.hpp"
#include "utils/utils.hpp"
#include "bitvectors/zombit_vector.hpp"
#include <sdsl/bit_vectors.hpp>
#include <iomanip>

using namespace std;


std::string g_vec_path = "";
std::string g_block_model = "";
uint64_t g_postings_list_size = 0;
sdsl::bit_vector g_bv;

// creating new vector v from w -> v[i] = w[i] - w[i-1]
void create_diff_vector(const vector<uint64_t> &seq_ref2, vector<uint64_t> &seq_diff_ref, uint64_t &sumOrig_r) {
    //cerr << ">> Creating difference vector...";
    for (uint64_t i = 1; i < seq_ref2.size(); i++) {
        if (seq_ref2[i] > seq_ref2[i - 1]) {
            seq_diff_ref[i] = seq_ref2[i] - seq_ref2[i - 1];
            sumOrig_r += (seq_ref2[i] - seq_ref2[i - 1]);
        } else {
            seq_diff_ref[i] = seq_ref2[i];
            sumOrig_r += seq_ref2[i];
        }
    }
    //cerr << " DONE" << endl;
}

void create_bit_vector(sdsl::bit_vector &bv, const vector<uint64_t> &vec_ref, const uint64_t &n) {
    bv = sdsl::bit_vector(n + 1);

    for (uint64_t i = 0; i < n; i++) bv[i] = 0;

    uint64_t sum = vec_ref[0];
    bv[sum] = 1;
    for (uint64_t i = 1; i < vec_ref.size(); i++) {
        sum += vec_ref[i];
        bv[sum] = 1;
    }
}


template<class T>
void test_zombit(T &zombit,
    const uint32_t b,
    const std::string label,
    const vector<uint64_t> &r) {

  int32_t max_rec_depth = (int32_t) log2(b);
  float prev_bpp = 1000000.0;
  for (int32_t rec_level = 0; rec_level < max_rec_depth; rec_level++) {
    zombit.build_zombit(g_bv,rec_level, b, true, g_vec_path, g_block_model);

    chrono::duration<double, std::micro> ms_double;
    double time_avg = 0;
    double time_avg_total = 0;
    for (uint32_t j = 0; j < 3; j++) {
      time_avg = 0;
      for (uint64_t i = 0; i < r.size(); i++) {
        auto t1 = chrono::high_resolution_clock::now();
        zombit.nextGEQ(r[i]);
        auto t2 = chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        time_avg += ms_double.count();
      }
      time_avg_total += (time_avg / r.size());
    }

    float bpp = (float) zombit.size_in_bits() / g_postings_list_size;
    cout << label << ";" << b << ";" << bpp;
    cout << ";" << ((float)zombit.u_vector_size_in_bits() / g_postings_list_size);
    cout << ";" << ((float)zombit.o_vector_size_in_bits() / g_postings_list_size);
    cout << ";" << ((float)zombit.m_vector_size_in_bits() / g_postings_list_size);
    cout << ";" << ((float)zombit.u_vector_size_in_bits() / zombit.size_in_bits());
    cout << ";" << ((float)zombit.o_vector_size_in_bits() / zombit.size_in_bits());
    cout << ";" << ((float)zombit.m_vector_size_in_bits() / zombit.size_in_bits());
    cout << ";" << zombit.block_n << ";" << zombit.m_blocks << ";" << zombit.runs_n << ";" << rec_level;

    std::cout << ";" << (time_avg_total/3) << "\n";
    //std::string uname = "./data/zombit/small_u_vec_b" + std::to_string(b) + ".dat";
    //std::string oname = "./data/zombit/small_o_vec_b" + std::to_string(b) + ".dat";
    //std::string mname = "./data/zombit/small_m_vec_b" + std::to_string(b) + ".dat";
    //sdsl::store_to_file(zombit.u_vector, uname);
    //sdsl::store_to_file(zombit.o_vector, oname);
    //sdsl::store_to_file(zombit.m_vector, mname);
    //std::cout << "block:" << b << ", U,O,M vector stored\n";
    if (prev_bpp == bpp) break;
    prev_bpp = bpp;
  }
}


int main(int argc, char *argv[]) {

	if (argc < 5) {
        cout << ">> Program usage: " << argv[0] << " <input_file> <mode> <zombit_models> <vec_path> <rec_model> \n";
        exit(1);
    }
    //std::string output_file = "./data/test_file.dat";
    //uint64_t n = 100000000;
    //utils::copy_n_blocks(argv[1], output_file, n);

    string curr_time = utils::current_time2str();
    cerr << ">> Program START time: " << curr_time << endl;
    string mode = argv[2];
    uint64_t postings_list_size = 0;
    if (mode == "raw") {

        vector<uint64_t> seq;
        utils::read_input_file<uint64_t>(argv[1], seq);
        g_postings_list_size = seq.size();

        vector<uint64_t> seq_diff(seq.size());
        seq_diff[0] = seq[0];
        uint64_t sumOrig = seq[0];
        create_diff_vector(seq, seq_diff, sumOrig);
        seq.clear();
        seq.shrink_to_fit();

        // creating bit_vector
        create_bit_vector(g_bv, seq_diff, sumOrig);
        seq_diff.clear();
        seq_diff.shrink_to_fit();
        //sdsl::store_to_file(bv, "/home/scratch-hdd/osiipola/gov2_as_bitvector.dat");
    } else if (mode == "notraw") {
          sdsl::load_from_file(g_bv, argv[1]);
          g_postings_list_size = 0;
          for (uint64_t i = 0; i < g_bv.size(); i++) {
              if (g_bv[i] == 1) g_postings_list_size++;
          }
    }

    // setting global variables
    std::string run_mode = argv[3];
    g_vec_path = argv[4];
    g_block_model = argv[5];

    // reading block lengths for test from user input
    uint32_t b_n;
    std::cin >> b_n;
    vector<uint32_t> block_sizes(b_n);
    for (int i = 0; i < b_n; i++) std::cin >> block_sizes[i];

    // creating test query values
    uint64_t n = g_bv.size() > 1000000 ? 1000000 : g_bv.size();
    uint64_t u = g_bv.size();
    vector<uint64_t> benchmark_quesries(n);
    srand(0);
    for (uint32_t i = 0; i < n; i++) benchmark_quesries[i] = rand() % u + 1;
    g_bv = sdsl::bit_vector(0);

    cout << "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)\n";

    ////////////////////////
    //
    // ACTUAL ZOMBIT TESTING
    //
    ////////////////////////



    // bit_vector, bit_vector, bit_vector
    if (run_mode[0] == '1') {
      for (uint32_t b : block_sizes ) {
        zombit_bv_bv_bv zombit{};
        test_zombit(zombit, b, "<bv,bv,bv>", benchmark_quesries);
      }
    }

    ////  bv,bv, rrr
    if (run_mode[1] == '1') {
      for (uint32_t b : block_sizes ) {
        zombit_bv_bv_rrr zombit{};
        test_zombit(zombit, b, "<bv,bv,rrr>", benchmark_quesries);
      }
    }

    if (run_mode[2] == '1') {
      for (uint32_t b : block_sizes ) {
        zombit_hyb_rrr_rrr zombit{};
        test_zombit(zombit, b, "<hyb,rrr,rrr>", benchmark_quesries);
      }
    }

    //  bv,bv,sd
    if (run_mode[3] == '1') {
      for (uint32_t b : block_sizes ) {
        zombit_bv_bv_sd zombit{};
        test_zombit(zombit, b, "<bv,bv,sd>", benchmark_quesries);
      }
    }

    curr_time = utils::current_time2str();
    cerr << ">> Program END time: " << curr_time << endl;

  	return 0;
}
