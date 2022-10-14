#include <gtest/gtest.h>
#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <math.h>
#include <string>
#include <sdsl/rank_support_v5_ossi.hpp>
//#include <sdsl/rank_support_v5O2.hpp>
#include "../src/bitvectors/rank_support_v5O2.hpp"

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

TEST(sdslOssiHack, printSum) {
    //int n = 5*2048-2;
    //int n = 4*2048+ 512;
    int n = 4*2048+ 2048 - 63;
    sdsl::bit_vector bv(n);// = {0,1,1,1,0,0,1,0,1,0,0,0,0,0,1};

    for (int i = 0; i < n; i++) bv[i] = 1;
    //bv[2048-1] = 1;
    //bv[2*2048-1] = 1;
    //bv[3*2048-1] = 1;
    //bv[4*2048-1] = 1;

    //rank_support_v5_ossi<1> rank_v5_O(&bv);
    sdsl::rank_support_v5O2<1> o_rank(&bv);




}

// helper function for NextGEQ test
uint64_t scan_nextGEQ2(sdsl::bit_vector &bv, uint64_t x) {
    uint64_t res = 0;
    for (uint64_t i = x; i < bv.size(); i++) {
        if (bv[i] == 1) {
            res = i;
            break;
        }
    }
    return res;
}

TEST(RankScanSucc, NextGEQSmallResInNextWordBlock) {
    sdsl::bit_vector bv(2*64);

    bv[64 + 10] = 1;
    bv[64 + 11] = 1;
    bv[64 + 33] = 1;
    bv[64 + 46] = 1;
    bv[64 + 47] = 1;
    bv[64 + 48] = 1;
    bv[64 + 60] = 1;
    bv[64 + 62] = 1;

    sdsl::rank_support_v5O2<1> rank_b(&bv);
    uint32_t bv_size = bv.size();
    for (int i = 0; i < 2*64; i++) {
        ASSERT_EQ(rank_b.nextGEQ(bv, i), scan_nextGEQ2(bv, i));
    }
}

TEST(RankScanSucc, NextGEQSmallResInNextWordBlock2) {
    for (int j = 0; j < 2*64; j++) {
        sdsl::bit_vector bv(2*64);
        bv[j] = 1;
        sdsl::rank_support_v5O2<1> rank_b(&bv);

        for (int i = 0; i < 2*64; i++) {
            ASSERT_EQ(rank_b.nextGEQ(bv, i), scan_nextGEQ2(bv, i));
        }
    }
}

TEST(RankScanSucc, RandomBVZeroSuperBlocks) {
    int rounds = 1000;
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
        //std::cout << "---\n";
        //std::cout << bv << "\n";
        //bv[n-1] = 1;
        sdsl::rank_support_v5O2<1> rank_b(&bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(rank_b.nextGEQ(bv, x), scan_nextGEQ2(bv, x));
        }
    }
}

TEST(RankScanSucc, RandomBVFewSuperBlocks) {
    int rounds = 1000;
    srand(1);
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 4096 + 2048; // size of the bv
        int m = rand() % n; // number of 1s
        vector<int> ones(n);
        for (int j = 0; j < n; j++) ones[j] = j;
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(ones), std::end(ones), rng);
        sdsl::bit_vector bv(n);
        for (int j = 0; j < m; j++) bv[ones[j]] = 1;
        sdsl::rank_support_v5O2<1> rank_b(&bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(rank_b.nextGEQ(bv, x), scan_nextGEQ2(bv, x));
        }
    }
}

TEST(RankScanSucc, AllZeros) {
    int rounds = 100;
    srand(1);
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 4096 + 2048; // size of the bv
        sdsl::bit_vector bv(n);
        sdsl::rank_support_v5O2<1> rank_b(&bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(rank_b.nextGEQ(bv, x), scan_nextGEQ2(bv, x));
        }
    }
}

TEST(RankScanSucc, AllOnes) {
    int rounds = 100;
    srand(1);
    for (int i = 0; i < rounds; i++) {
        int n = rand() % 4096 + 2048; // size of the bv
        sdsl::bit_vector bv(n);
        for (int i = 0; i < n; i++) bv[i] = 1;
        sdsl::rank_support_v5O2<1> rank_b(&bv);
        for (int x = 0; x < n; x++) {
            ASSERT_EQ(rank_b.nextGEQ(bv, x), scan_nextGEQ2(bv, x));
        }
    }
}

TEST(RankScanSucc, SmallSampleNextGEQ) {
    sdsl::bit_vector bv;
    sdsl::load_from_file(bv, "../data/small_sample_as_bv.dat");
    sdsl::rank_support_v5O2<1> rank_b(&bv);
    for (int i = 0; i < bv.size(); i++) {
        ASSERT_EQ(rank_b.nextGEQ(bv, i), scan_nextGEQ2(bv, i));
    }
}


