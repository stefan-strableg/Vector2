#include <gtest/gtest.h>
#include "../inc/Vector2.hpp"

TEST(Vector2, Vector2)
{
    GTEST_ASSERT_EQ(Vector2(1,1), Vector2(1,1));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}