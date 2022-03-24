
#include <gtest/gtest.h>
#include "../bitArray/bitArray.hpp"

// Demonstrate some basic assertions.
TEST(bit_vector_test, BitVectorSimpleTest) {
  // Expect two strings not to be equal.
  //EXPECT_STRNE("hello", "world");

  ////test for breaking test
  //EXPECT_STRNE("hello", "hello");

  //// Expect equality.
  //EXPECT_EQ(7 * 6, 42);
  //

  BitArray bv = BitArray(1);

  EXPECT_EQ(bv.get(1), 0) // first bit is zero;

  bv.set(1,true);

  EXPECT_EQ(bv.get(1), 1) // first bit is zero;
}

