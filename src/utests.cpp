#include <gtest/gtest.h>
#include "../inc/Vector2.hpp"


class Vectors : public testing::Test {
 protected:
    Vector2<double> v_d;
    Vector2<float> v_f;
    Vector2<int> v_i;
    Vector2<char> v_c;

    Vector2<double> v_d_3_4;
    Vector2<float> v_f_3_4;
    Vector2<int> v_i_3_4;
    Vector2<char> v_c_3_4;

    Vector2<double> v_d_10_10;
    Vector2<float> v_f_10_10;
    Vector2<int> v_i_10_10;
    Vector2<char> v_c_10_10;

    Vectors() 
    : v_d_3_4(3.0, 4.0)
    , v_f_3_4(3.f, 4.f)
    , v_i_3_4(3, 4)
    , v_c_3_4(3,4)
    , v_d_10_10(10.0, 10.0)
    , v_f_10_10(10.f, 10.f)
    , v_i_10_10(10, 10)
    , v_c_10_10(10, 10)
    {}
};

TEST(Vector2, DefaultConstructor)
{
    Vector2<double> v_d;
    Vector2<int> v_i;

    EXPECT_EQ(v_d.x, 0.0);
    EXPECT_EQ(v_d.y, 0.0);
    EXPECT_EQ(v_i.x, 0);
    EXPECT_EQ(v_i.y, 0);
}

TEST(Vector2, SingleValueConstructor)
{
    Vector2<double> v_d(5);
    Vector2<int> v_i(5);

    EXPECT_EQ(v_d.x, 5.0);
    EXPECT_EQ(v_d.y, 5.0);
    EXPECT_EQ(v_i.x, 5);
    EXPECT_EQ(v_i.y, 5);
}

TEST(Vector2, ParameterizedConstructor)
{
    Vector2<double> v_d(3,4);
    Vector2<int> v_i(3,4);

    EXPECT_EQ(v_d.x, 3.0);
    EXPECT_EQ(v_d.y, 4.0);
    EXPECT_EQ(v_i.x, 3);
    EXPECT_EQ(v_i.y, 4);
}

TEST(Vector2, ConstructorFromPair)
{
    std::pair<double, double> p_d(3.0, 4.0);
    std::pair<int, int> p_i(3,4);

    Vector2<double> v_d(p_d);
    Vector2<int> v_i(p_i);

    EXPECT_EQ(v_d.x, 3.0);
    EXPECT_EQ(v_d.y, 4.0);
    EXPECT_EQ(v_i.x, 3);
    EXPECT_EQ(v_i.y, 4);
}

TEST(Vector2, ConstructorFromPairRVal)
{
    std::pair<double, double> p_d(3.0, 4.0);
    std::pair<int, int> p_i(3,4);

    Vector2<double> v_d(std::move(p_d));
    Vector2<int> v_i(std::move(p_i));

    EXPECT_EQ(v_d.x, 3.0);
    EXPECT_EQ(v_d.y, 4.0);
    EXPECT_EQ(v_i.x, 3);
    EXPECT_EQ(v_i.y, 4);
}

TEST(Vector2, CopyConstructor)
{
    Vector2<double> v_d1(3,4);
    Vector2<int> v_i1(3,4);

    Vector2<double> v_d(v_d1);
    Vector2<int> v_i(v_i1);

    EXPECT_EQ(v_d.x, 3.0);
    EXPECT_EQ(v_d.y, 4.0);
    EXPECT_EQ(v_i.x, 3);
    EXPECT_EQ(v_i.y, 4);
}

TEST(Vector2, MoveConstructor)
{
    Vector2<double> v_d1(3,4);
    Vector2<int> v_i1(3,4);

    Vector2<double> v_d(std::move(v_d1));
    Vector2<int> v_i(std::move(v_i1));

    EXPECT_EQ(v_d.x, 3.0);
    EXPECT_EQ(v_d.y, 4.0);
    EXPECT_EQ(v_i.x, 3);
    EXPECT_EQ(v_i.y, 4);
}

TEST_F(Vectors, GetAngle)
{
    EXPECT_EQ(v_d_10_10.getAngle(), degrees(45));
    EXPECT_EQ(v_i_3_4.getAngle(), degrees(180));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}