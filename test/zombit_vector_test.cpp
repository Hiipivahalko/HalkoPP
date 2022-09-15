#include "../src/bitvectors/zombit_vector.hpp"
#include <gtest/gtest.h>
#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <math.h>

using namespace std;


template <typename T1, typename T2, typename T3>
struct TypeDefinitions {
    typedef T1 First;
    typedef T2 Second;
    typedef T3 Thrid;
};

template <class T>
class ZombitTest : public ::testing::Test {
    protected:
        //Zombit<T1,T2,T3> zom_vec;
        Zombit<typename T::First, typename T::Second, typename T::Thrid> zom_vec;
        //sdsl::bit_vector bv = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 };
        //uint32_t type_size = sizeof(T1)*8;
};

using TestTypes = ::testing::Types< TypeDefinitions<sdsl::bit_vector, sdsl::bit_vector, sdsl::bit_vector> >;
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

TYPED_TEST(ZombitTest, random_bv1_small) {
    int rounds = 10;
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 20 + 90; // size of the bv
        int m = rand() % n; // number of 1s
        vector<int> ones(n);
        for (int j = 0; j < n; j++) ones[j] = j;
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(ones), std::end(ones), rng);
        sdsl::bit_vector bv(n);
        for (int j = 0; j < m; j++) bv[ones[j]] = 1;
        this->zom_vec.build_zombit(bv);
    }
}

// NextGEQ tests

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
