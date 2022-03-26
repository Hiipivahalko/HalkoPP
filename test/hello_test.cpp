#include "../src/hello.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");

    //test for breaking test
    //EXPECT_STRNE("hello", "hello");

    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, PowerOfTWO) {
    EXPECT_EQ(hello::power2(1), 1);
    EXPECT_EQ(hello::power2(2), 4);
    EXPECT_EQ(hello::power2(4), 16);
}

