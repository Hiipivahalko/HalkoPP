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


// creating new vector v from w -> v[i] = w[i] - w[i-1]
void create_diff_vector(const vector<uint64_t> &seq_ref2, vector<uint64_t> &seq_diff_ref, uint64_t &sumOrig_r) {
    cerr << ">> Creating difference vector...";
    for (uint64_t i = 1; i < seq_ref2.size(); i++) {
        if (seq_ref2[i] > seq_ref2[i - 1]) {
            seq_diff_ref[i] = seq_ref2[i] - seq_ref2[i - 1];
            sumOrig_r += (seq_ref2[i] - seq_ref2[i - 1]);
        } else {
            seq_diff_ref[i] = seq_ref2[i];
            sumOrig_r += seq_ref2[i];
        }
    }
    cerr << " DONE" << endl;
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

template <class T>
void print_zombit_size_test_res(T &zombit,  std::string label, uint32_t b, uint64_t postings_list_size, uint32_t r) {


        float bpp = (float) zombit.size_in_bits() / postings_list_size;

        cout << label << ";" << b << ";" << bpp;
        cout << ";" << ((float)zombit.u_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.o_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.m_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.u_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << ((float)zombit.o_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << ((float)zombit.m_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << zombit.block_n << ";" << zombit.m_blocks << ";" << zombit.runs_n << ";" << r;
}

template <class T>
void benchmark_zombit(T &zombit, std::string label, vector<uint64_t> &r) {
    chrono::duration<double, std::micro> ms_double;
    double time_avg = 0;
    for (uint64_t i = 0; i < r.size(); i++) {
        auto t1 = chrono::high_resolution_clock::now();
        zombit.nextGEQ(r[i]);
        auto t2 = chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        time_avg += ms_double.count();
    }
    std::cout << ";" << ((double)time_avg/r.size()) << "\n";
}


int main(int argc, char *argv[]) {
  	hello::message();

	if (argc < 3) {
        cout << ">> Program usage: " << argv[0] << " <input_file> <mode>\n";
        exit(1);
    }
    //std::string output_file = "./data/test_file.dat";
    //uint64_t n = 100000000;
    //utils::copy_n_blocks(argv[1], output_file, n);

    string curr_time = utils::current_time2str();
    cerr << ">> Program START time: " << curr_time << endl;
    string mode = argv[2];
    sdsl::bit_vector bv;
    uint64_t postings_list_size = 0;
    if (mode == "raw") {

        vector<uint64_t> seq;
        utils::read_input_file<uint64_t>(argv[1], seq);
        postings_list_size = seq.size();

        vector<uint64_t> seq_diff(seq.size());
        //seq_diff.resize(input_seq.size());
        seq_diff[0] = seq[0];
        uint64_t sumOrig = seq[0];
        create_diff_vector(seq, seq_diff, sumOrig);
        seq.clear();
        seq.shrink_to_fit();

        //uint64_t n = seq_diff.size();

        // creating bit_vector
        cerr << ">> Creating bit vector of " << sumOrig << " bits" << endl;
        create_bit_vector(bv, seq_diff, sumOrig);
        seq_diff.clear();
        seq_diff.shrink_to_fit();
        cerr << ">> Done..." << endl;
    } else if (mode == "notraw") {
          std::cerr << ">> reading bit vector from file...";
          sdsl::load_from_file(bv, argv[1]);
          std::cerr << "DONE\n";
          std::cerr << ">> bit vector size: " << bv.size() << "\n";
          for (uint64_t i = 0; i < bv.size(); i++) {
              if (bv[i] == 1) postings_list_size++;
          }
    }

    //postings_list_size = 5055078461;


    //sdsl::store_to_file(bv, "./gov2_as_bitvector.dat");

    // bloc size 10 is the article "optimal"
    std::string run_mode = argv[3];
    //vector<uint32_t> block_sizes = {8,10,16,32,64,128,256,512,1024,2048};
    vector<uint32_t> block_sizes = {8, 16, 32, 64, 128, 256,512,1024,2048,4096,8192,16384};
    //vector<uint32_t> block_sizes = {16384};
    uint64_t n = bv.size() > 1000000 ? 1000000 : bv.size();
    uint64_t u = bv.size();
    vector<uint64_t> benchmark_quesries(n);
    srand(0);
    for (uint32_t i = 0; i < n; i++) benchmark_quesries[i] = rand() % u + 1;

    cout << "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s;recursio level;nextGEQ avg (μs)\n";
    if (run_mode[0] == '1') {
      // bit_vector, bit_vector, bit_vector
      for (uint32_t b : block_sizes ) {
        int32_t rec_l = (int32_t) log2(b);
        for (int32_t r = rec_l; r >= 0; r--) {
          zombit_bv_bv_bv zom_bv{};
          std::string label = "<bv,bv,bv>";
          cerr << ">> building zombit" << label << "-" << b << " with r=" << r <<" ...";
          zom_bv.build_zombit(bv,r,b);
          cerr << "building DONE\n";
          print_zombit_size_test_res(zom_bv, label, b, postings_list_size, r);
          benchmark_zombit(zom_bv, label, benchmark_quesries);
        }
      }
    }
    if (run_mode[1] == '1') {

      ////  rrr, rrr, rrr
      for (uint32_t b : block_sizes ) {
        int32_t rec_l = (int32_t) log2(b);
        for (int32_t r = rec_l; r >= 0; r--) {
          zombit_rrr_rrr_rrr zom_bv{};
          std::string label = "<rrr,rrr,rrr>";
          cerr << ">> building zombit" << label << "-" << b << " with r=" << r <<" ...";
          zom_bv.build_zombit(bv,r,b);
          cerr << "building DONE\n";
          print_zombit_size_test_res(zom_bv, label, b, postings_list_size, r);
          benchmark_zombit(zom_bv, label, benchmark_quesries);
        }
      }
    }
    if (run_mode[2] == '1') {

      //  sd,sd,sd
      for (uint32_t b : block_sizes ) {
        int32_t rec_l = (int32_t) log2(b);
        for (int32_t r = rec_l; r >= 0; r--) {
          zombit_sd_sd_sd zom_bv{};
          std::string label = "<sd,sd,sd>";
          cerr << ">> building zombit" << label << "-" << b << " with r=" << r <<" ...";
          zom_bv.build_zombit(bv,r,b);
          cerr << "building DONE\n";
          print_zombit_size_test_res(zom_bv, label, b, postings_list_size, r);
          benchmark_zombit(zom_bv, label, benchmark_quesries);
        }
      }
    }
    if (run_mode[3] == '1') {

      // bit_vector_il, bit_vector_il, bit_vector_il
      for (uint32_t b : block_sizes ) {
        int32_t rec_l = (int32_t) log2(b);
        for (int32_t r = rec_l; r >= 0; r--) {
          zombit_bvIL_bvIL_bvIL zom_bv{};
          std::string label = "<bv_il,bv_il,bv_il>";
          cerr << ">> building zombit" << label << "-" << b << " ...";
          zom_bv.build_zombit(bv,r,b);
          cerr << "building DONE\n";
          print_zombit_size_test_res(zom_bv, label, b, postings_list_size, r);
          benchmark_zombit(zom_bv, label, benchmark_quesries);
        }
      }
    }
    if (run_mode[4] == '1') {

      //  hyb, rrr, rrr
      for (uint32_t b : block_sizes ) {
        int32_t rec_l = (int32_t) log2(b);
        for (int32_t r = rec_l; r >= 0; r--) {
          zombit_hyb_rrr_rrr zom_bv{};
          std::string label = "<hyb,rrr,rrr>";
          cerr << ">> building zombit" << label << "-" << b << " with r=" << r <<" ...";
          zom_bv.build_zombit(bv,r,b);
          cerr << "building DONE\n";
          print_zombit_size_test_res(zom_bv, label, b, postings_list_size, r);
          benchmark_zombit(zom_bv, label, benchmark_quesries);
        }
      }
    }
    curr_time = utils::current_time2str();
    cerr << ">> Program END time: " << curr_time << endl;

  	return 0;
}
