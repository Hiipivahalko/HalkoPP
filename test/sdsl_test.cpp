#include <gtest/gtest.h>
#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <math.h>
#include <string>

using namespace std;


TEST(saveSDSLObject, saveBitvector) {
    sdsl::bit_vector bv = {1,0,1,0,1,0};
    string filename = "./test_sdsl_bv.dat";
    sdsl::store_to_file(bv, filename);
    sdsl::bit_vector bv_load;
    sdsl::load_from_file(bv_load, filename);

    ASSERT_EQ(bv.size(), bv_load.size());
    for (int i = 0; i < bv.size(); i++) ASSERT_EQ(bv[i], bv_load[i]);
}
