#include <gtest/gtest.h>
#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <math.h>
#include <string>

using namespace std;


TEST(sdslTEST, saveBitvector) {
    sdsl::bit_vector bv = {1,0,1,0,1,0};
    string filename = "./test_sdsl_bv.dat";
    sdsl::store_to_file(bv, filename);
    sdsl::bit_vector bv_load;
    sdsl::load_from_file(bv_load, filename);

    ASSERT_EQ(bv.size(), bv_load.size());
    for (int i = 0; i < bv.size(); i++) ASSERT_EQ(bv[i], bv_load[i]);
}

TEST(sdslTEST, select_over_m) {
    //sdsl::bit_vector bv = {0,0,1,1, 0,1, 0,0,0, 0};
    sdsl::bit_vector bv = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1};
    sdsl::select_support_mcl<1> s(&bv);

    //for (int i = 1; i <= 10; i++) {
    //    std::cout << "i:" << i << " -- " << s.select(i) << "\n";
    //}
    //cout << s.select(43) << endl;
    //cout << s.select(44) << endl;
    //cout << s.select(45) << endl;
}

TEST(sdslTEST, clz_test) {
    sdsl::bit_vector bv(64);

    //bv[0] = 1;
    bv[63] = 1;
    for (int i = 0; i < 64; i++) {
        int z = __builtin_ctzll(bv.data()[0]);
        //std::cout << z << "\n";
    }
}
