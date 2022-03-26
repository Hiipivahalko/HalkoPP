
#include "../src/bitArray/bitArray.hpp"
#include <gtest/gtest.h>
#include <random>

using namespace std;

//namespace {

//class BitVectorTest : public testing::Test {
//  protected:
//    void SetUp() override {
//      //bv_.set(1,true);
//    }
//
//    BitVector bv_ = BitVector(2);
//};

// Demonstrate some basic assertions.
TEST(BitVectorTest, BitVectorSimpleTest) {

  BitVector bv_ = BitVector(1);

  EXPECT_EQ(bv_.get(1), 0) << "Bit 1 was not set to 0 (false)"; // first bit is zero;

  bv_.set(1, true);

  EXPECT_EQ(bv_.get(1), 1); // first bit is zero;
  bv_.set(1, false);
  EXPECT_EQ(bv_.get(1), 0) << "Bit 1 was not set to 0 (false)"; // first bit is zero;


  BitVector bv2_ = BitVector(10);
  for (int i = 1; i <= 10; i++ ) EXPECT_EQ(bv2_.get(i), 0);
  for (int i = 1; i <= 10; i++ ) bv2_.set(i, true);
  for (int i = 1; i <= 10; i++ ) EXPECT_EQ(bv2_.get(i), 1);
  for (int i = 1; i <= 10; i++ ) bv2_.set(i, false);
  for (int i = 1; i <= 10; i++ ) EXPECT_EQ(bv2_.get(i), 0);

}

TEST(BitVectorTest, BitVectorRandomTest) {
    for (int i = 1; i <= 1000; i++) {
        int n = rand() % 1000 + 30;
        BitVector bv = BitVector(n);
        int a[n+1]{0};
        for (int k = 1; k <= n; k++) {
            int val = rand() % 2;
            bool bitVal = val == 1 ? true : false;
            bv.set(k, bitVal);
            a[k] = val;
        }

        for (int k = 1; k <= n; k++) EXPECT_EQ(bv.get(k), a[k]);
    }
}
//}



