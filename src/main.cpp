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

//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_bv_bv;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_bv_bvIL;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_bv_sd;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_bv_rrr;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_bvIL_bv;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_bvIL_bvIL;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_bvIL_sd;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_bvIL_rrr;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_sd_bv;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_sd_bvIL;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_sd_sd;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_sd_rrr;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_rrr_bv;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_rrr_bvIL;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_rrr_sd;
//typedef Zombit<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_rrr_rrr;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_bv_bv;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_bv_bvIL;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_bv_sd;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_bv_rrr;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_bvIL_bv;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_bvIL_bvIL;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_bvIL_sd;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_bvIL_rrr;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_sd_bv;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_sd_bvIL;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_sd_sd;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_sd_rrr;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_rrr_bv;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_rrr_bvIL;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_rrr_sd;
//typedef Zombit<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_rrr_rrr;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_bv_bv;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_bv_bvIL;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_bv_sd;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_bv_rrr;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_bvIL_bv;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_bvIL_bvIL;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_bvIL_sd;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_bvIL_rrr;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_sd_bv;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_sd_bvIL;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_sd_sd;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_sd_rrr;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_rrr_bv;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_rrr_bvIL;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_rrr_sd;
//typedef Zombit<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_rrr_rrr;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_bv_bv;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_bv_bvIL;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_bv_sd;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_bv_rrr;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_bvIL_bv;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_bvIL_bvIL;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_bvIL_sd;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_bvIL_rrr;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_sd_bv;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_sd_bvIL;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_sd_sd;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_sd_rrr;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_rrr_bv;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_rrr_bvIL;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_rrr_sd;
//typedef Zombit<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_rrr_rrr;
//typedef Zombit<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_hyb_rrr_rrr;

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
void print_zombit_size_test_res(T &zombit,  std::string label, uint32_t b, uint64_t postings_list_size) {


        float bpp = (float) zombit.size_in_bits() / postings_list_size;

        cout << label << ";" << b << ";" << bpp;
        cout << ";" << ((float)zombit.u_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.o_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.m_vector_size_in_bits() / postings_list_size);
        cout << ";" << ((float)zombit.u_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << ((float)zombit.o_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << ((float)zombit.m_vector_size_in_bits() / zombit.size_in_bits());
        cout << ";" << zombit.block_n << ";" << zombit.m_blocks << ";" << zombit.runs_n;
}

template <class T>
void benchmark_zombit(T &zombit, std::string label, vector<uint64_t> &r) {
    chrono::duration<double, std::milli> ms_double;
    double time_avg = 0;
    for (uint64_t i = 0; i < r.size(); i++) {
        auto t1 = chrono::high_resolution_clock::now();
        zombit.nextGEQ(r[i]);
        auto t2 = chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        time_avg += ms_double.count();
    }
    std::cout << ";" << time_avg << "\n";
}

int main(int argc, char *argv[]) {
  	hello::message();

	if (argc < 3) {
        cout << ">> Program usage: " << argv[0] << " <input_file> <mode>\n";
        exit(1);
    }
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

    //vector<uint32_t> block_sizes = {32};
    // bloc size 10 is the article "optimal"
    vector<uint32_t> block_sizes = {8,10,16,32,64,128,256,512,1024,2048};
    uint64_t n = bv.size() > 1000000 ? 1000000 : bv.size();
    uint64_t u = bv.size();
    vector<uint64_t> benchmark_quesries(n);
    srand(0);
    for (uint32_t i = 0; i < n; i++) benchmark_quesries[i] = rand() % u + 1;

    cout << "zombit<U,O,M>;block size;overall size;U size;O size;M size;U%;O%;M%;number of blocks;mixed blocks;runs of 1s\n";
    // bit_vector, bit_vector, bit_vector
    for (uint32_t b : block_sizes ) {
        zombit_bv_bv_bv zom_bv{};
        std::string label = "<bv,bv,bv>";
        cerr << ">> building zombit" << label << "-" << b << " ...";
        zom_bv.build_zombit(bv,0,b);
        cerr << "building DONE\n";
        print_zombit_size_test_res(zom_bv, label, b, postings_list_size);
        benchmark_zombit(zom_bv, label, benchmark_quesries);
    }
    //  rrr, rrr, rrr
    for (uint32_t b : block_sizes ) {
		zombit_rrr_rrr_rrr zom_bv{};
        std::string label = "<rrr,rrr,rrr>";
        cerr << ">> building zombit" << label << "-" << b << " ...";
        zom_bv.build_zombit(bv,0,b);
        cerr << "building DONE\n";

        print_zombit_size_test_res(zom_bv, label, b, postings_list_size);
        benchmark_zombit(zom_bv, label, benchmark_quesries);
    }
    //  sd,sd,sd
    for (uint32_t b : block_sizes ) {
        zombit_sd_sd_sd zom_bv{};
        std::string label = "<sd,sd,sd>";
        cerr << ">> building zombit" << label << "-" << b << " ...";
        zom_bv.build_zombit(bv,0,b);
        cerr << "building DONE\n";

        print_zombit_size_test_res(zom_bv, label, b, postings_list_size);
        benchmark_zombit(zom_bv, label, benchmark_quesries);
    }
    // bit_vector_il, bit_vector_il, bit_vector_il
    for (uint32_t b : block_sizes ) {
        zombit_bvIL_bvIL_bvIL zom_bv{};

        std::string label = "<bv_il,bv_il,bv_il>";
        cerr << ">> building zombit" << label << "-" << b << " ...";
        zom_bv.build_zombit(bv,0,b);
        cerr << "building DONE\n";
        print_zombit_size_test_res(zom_bv, label, b, postings_list_size);
        benchmark_zombit(zom_bv, label, benchmark_quesries);
    }
    //  hyb, rrr, rrr
    for (uint32_t b : block_sizes ) {
        zombit_hyb_rrr_rrr zom_bv{};
        std::string label = "<hyb,rrr,rrr>";
        cerr << ">> building zombit" << label << "-" << b << " ...";
        zom_bv.build_zombit(bv,0,b);
        cerr << "building DONE\n";

        print_zombit_size_test_res(zom_bv, label, b, postings_list_size);
        benchmark_zombit(zom_bv, label, benchmark_quesries);
    }
    curr_time = utils::current_time2str();
    cerr << ">> Program END time: " << curr_time << endl;

  	return 0;
}
