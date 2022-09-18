#include "../src/bitvectors/zombit_vector.hpp"
#include <gtest/gtest.h>
#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <math.h>

using namespace std;


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
struct TypeDefinitions {
    typedef T1 T_u_vec;
    typedef T2 T_u_vec_rank;
    typedef T3 T_o_vec;
    typedef T4 T_o_vec_rank;
    typedef T5 T_o_vec_slc;
    typedef T6 T_m_vec;
    typedef T7 T_m_vec_rank;
    typedef T8 T_m_vec_slc;
};

template <class T>
class ZombitTest : public ::testing::Test {
    protected:
        //Zombit<T1,T2,T3> zom_vec;
        Zombit<typename T::T_u_vec, typename T::T_u_vec_rank,
            typename T::T_o_vec, typename T::T_o_vec_rank, typename T::T_o_vec_slc,
            typename T::T_m_vec, typename T::T_m_vec_rank, typename T::T_m_vec_slc> zom_vec;
        //sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 };
        //uint32_t type_size = sizeof(T1)*8;
};


//typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_bv_bv_test;

typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_bv_bv_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_bv_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_bv_sd_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_bv_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_bvIL_bv_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_bvIL_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_bvIL_sd_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_bvIL_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_sd_bv_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_sd_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_sd_sd_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_sd_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bv_rrr_bv_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bv_rrr_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bv_rrr_sd_test;
typedef TypeDefinitions<sdsl::bit_vector, sdsl::rank_support_v5<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bv_rrr_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_bv_bv_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_bv_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_bv_sd_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_bv_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_bvIL_bv_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_bvIL_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_bvIL_sd_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_bvIL_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_sd_bv_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_sd_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_sd_sd_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_sd_rrr_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_bvIL_rrr_bv_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_bvIL_rrr_bvIL_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_bvIL_rrr_sd_test;
typedef TypeDefinitions<sdsl::bit_vector_il<>, sdsl::rank_support_il<0>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_bvIL_rrr_rrr_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_bv_bv_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_bv_bvIL_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_bv_sd_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_bv_rrr_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_bvIL_bv_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_bvIL_bvIL_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_bvIL_sd_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_bvIL_rrr_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_sd_bv_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_sd_bvIL_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_sd_sd_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_sd_rrr_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_sd_rrr_bv_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_sd_rrr_bvIL_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_sd_rrr_sd_test;
typedef TypeDefinitions<sdsl::sd_vector<>, sdsl::sd_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_sd_rrr_rrr_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_bv_bv_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_bv_bvIL_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_bv_sd_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_bv_rrr_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_bvIL_bv_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_bvIL_bvIL_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_bvIL_sd_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_bvIL_rrr_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_sd_bv_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_sd_bvIL_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_sd_sd_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_sd_rrr_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_rrr_rrr_bv_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_rrr_rrr_bvIL_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_rrr_rrr_sd_test;
typedef TypeDefinitions<sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_rrr_rrr_rrr_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_hyb_bv_bv_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_hyb_bv_bvIL_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_hyb_bv_sd_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_hyb_bv_rrr_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_hyb_bvIL_bv_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_hyb_bvIL_bvIL_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_hyb_bvIL_sd_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_hyb_bvIL_rrr_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_hyb_sd_bv_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_hyb_sd_bvIL_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_hyb_sd_sd_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_hyb_sd_rrr_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector, sdsl::rank_support_v5<1>, sdsl::select_support_mcl<1>> zombit_hyb_rrr_bv_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::bit_vector_il<>, sdsl::rank_support_il<1>, sdsl::select_support_il<1>> zombit_hyb_rrr_bvIL_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::sd_vector<>, sdsl::sd_vector<>::rank_1_type, sdsl::sd_vector<>::select_1_type> zombit_hyb_rrr_sd_test;
typedef TypeDefinitions<sdsl::hyb_vector<>, sdsl::hyb_vector<>::rank_0_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type,sdsl::rrr_vector<>, sdsl::rrr_vector<>::rank_1_type, sdsl::rrr_vector<>::select_1_type> zombit_hyb_rrr_rrr_test;

// helper function for NextGEQ test
uint64_t scan_nextGEQ(sdsl::bit_vector &bv, uint64_t x) {
    uint64_t res = 0;
    for (uint64_t i = x; i < bv.size(); i++) {
        if (bv[i] == 1) {
            res = i;
            break;
        }
    }
    return res;
}

//using TestTypes = ::testing::Types< zombit_bv_bv_bv_test >;
using TestTypes = ::testing::Types< zombit_bv_bv_bv_test,zombit_bvIL_bvIL_bvIL_test,zombit_sd_sd_sd_test,zombit_rrr_rrr_rrr_test >;
TYPED_TEST_CASE(ZombitTest, TestTypes);

TYPED_TEST(ZombitTest, zombitArticleValues) {

    sdsl::bit_vector bv = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0};
    uint32_t b = 2;
    this->zom_vec.build_zombit(bv,b);

    sdsl::bit_vector u_res = {1,0,1,0,1,0,1,1};
    sdsl::bit_vector o_res = {1,1,0,1,1,1,0,0};
    sdsl::bit_vector m_res = {1,0,0,1,1,0};

    for (uint32_t i = 0; i < u_res.size(); i++) ASSERT_EQ(this->zom_vec.u_vector[i], u_res[i]);
    for (uint32_t i = 0; i < o_res.size(); i++) ASSERT_EQ(this->zom_vec.o_vector[i], o_res[i]);
    for (uint32_t i = 0; i < m_res.size(); i++) ASSERT_EQ(this->zom_vec.m_vector[i], m_res[i]);
}

TYPED_TEST(ZombitTest, zombitSmallTest1) {

    sdsl::bit_vector bv = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0};
    uint32_t b = 4;
    this->zom_vec.build_zombit(bv,b);

    sdsl::bit_vector u_res = {0,0,0,1};
    sdsl::bit_vector o_res = sdsl::bit_vector();
    sdsl::bit_vector m_res = {1,1,1,0,0,0,0,1,1,1,1,0};

    for (uint32_t i = 0; i < u_res.size(); i++) ASSERT_EQ(this->zom_vec.u_vector[i], u_res[i]);
    for (uint32_t i = 0; i < o_res.size(); i++) ASSERT_EQ(this->zom_vec.o_vector[i], o_res[i]);
    for (uint32_t i = 0; i < m_res.size(); i++) ASSERT_EQ(this->zom_vec.m_vector[i], m_res[i]);
}

TYPED_TEST(ZombitTest, zombitSmallTest2) {

    sdsl::bit_vector bv = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0};
    uint32_t b = 3;
    this->zom_vec.build_zombit(bv,b);

    sdsl::bit_vector u_res = {1,1,0,0,1,1};
    sdsl::bit_vector o_res = {1,0,1,1,0,0};
    sdsl::bit_vector m_res = {0,1,1,1,1,0};

    for (uint32_t i = 0; i < u_res.size(); i++) ASSERT_EQ(this->zom_vec.u_vector[i], u_res[i]);
    for (uint32_t i = 0; i < o_res.size(); i++) ASSERT_EQ(this->zom_vec.o_vector[i], o_res[i]);
    for (uint32_t i = 0; i < m_res.size(); i++) ASSERT_EQ(this->zom_vec.m_vector[i], m_res[i]);
}

TYPED_TEST(ZombitTest, access_all_zeros) {
    sdsl::bit_vector bv = { 0,0,0,0,0,0,0,0,0,0 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]);
}


TYPED_TEST(ZombitTest, access_all_ones) {
    sdsl::bit_vector bv = { 1,1,1,1,1,1,1,1,1,1 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]);
}

TYPED_TEST(ZombitTest, access_all_small1) {
    sdsl::bit_vector bv = { 1,1,0,0,1,1,0,0,1,1 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]);
}

TYPED_TEST(ZombitTest, access_small2) {
    sdsl::bit_vector bv = { 1,0,1,0,1,0,1,0,1,0 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]) << " i:" << i << std::endl;
}

TYPED_TEST(ZombitTest, access_small3) {
    sdsl::bit_vector bv = { 0,1,0,1,0,1,0,1,0,1 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]) << " i:" << i << std::endl;
}

TYPED_TEST(ZombitTest, access_small4) {
    sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 };
    uint32_t bv_size = bv.size();
    uint32_t b = 2;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]) << " i:" << i << std::endl;
}

TYPED_TEST(ZombitTest, access_small5) {
    sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 };
    uint32_t bv_size = bv.size();
    uint32_t b = 3;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]) << " i:" << i << std::endl;
}

TYPED_TEST(ZombitTest, access_small6) {
    sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 };
    uint32_t bv_size = bv.size();
    uint32_t b = 4;

    this->zom_vec.build_zombit(bv, b);

    for (uint32_t i = 0; i < bv_size; i++) ASSERT_EQ(this->zom_vec.access(i), bv[i]) << " i:" << i << std::endl;
}


// NextGEQ tests
TYPED_TEST(ZombitTest, random_bv1_small) {
    int rounds = 10000;
    srand(1);
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 20 + 90; // size of the bv
        int m = rand() % n; // number of 1s
        vector<int> ones(n);
        for (int j = 0; j < n; j++) ones[j] = j;
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(ones), std::end(ones), rng);
        sdsl::bit_vector bv(n);
        for (int j = 0; j < m; j++) bv[ones[j]] = 1;
        bv[n-1] = 1;
        this->zom_vec.build_zombit(bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(this->zom_vec.nextGEQ(x), scan_nextGEQ(bv, x));
            //std::cout << "\n";
        }
    }
}

TYPED_TEST(ZombitTest, random_bv1_big) {
    int rounds = 100;
    //srand(1);
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 200 + 10000; // size of the bv
        int m = rand() % n; // number of 1s
        vector<int> ones(n);
        for (int j = 0; j < n; j++) ones[j] = j;
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(ones), std::end(ones), rng);
        sdsl::bit_vector bv(n);
        for (int j = 0; j < m; j++) bv[ones[j]] = 1;
        bv[n-1] = 1;
        this->zom_vec.build_zombit(bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(this->zom_vec.nextGEQ(x), scan_nextGEQ(bv, x));
            //std::cout << "\n";
        }
    }
}

// be sure that all bit vectors ends to 1, this helps tests

TYPED_TEST(ZombitTest, NextGEQSmall1) {

    sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1 };
    uint32_t bv_size = bv.size();
    std::vector<uint32_t> blocks = {2,3,4};
    for (uint32_t b : blocks) {

      sdsl::bit_vector bv_temp = sdsl::bit_vector(bv);
      this->zom_vec.build_zombit(bv_temp, b);

      for (uint32_t x = 0; x < bv_size; x++) {
        ASSERT_EQ(this->zom_vec.nextGEQ(x), scan_nextGEQ(bv_temp, x));
      }
    }
}
