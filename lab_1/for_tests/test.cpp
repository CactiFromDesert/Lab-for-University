#include <gtest/gtest.h>

#include "../utilits.hpp"

TEST(UtilitsTest, MidlPointTest)
{
    int a = -6;
    int b = 5;
    double x = midl_point(a, b);

    EXPECT_EQ(x, -0.5);
}

TEST(UtilitsTest, MidlPointTest2)
{
    int a = -9;
    int b = -2;
    double x = midl_point(a, b);

    EXPECT_EQ(x, -5.5);
}

TEST(UtilitsTest, MidlPointTest3)
{
    int a = 0;
    int b = 8;
    double x = midl_point(a, b);

    EXPECT_EQ(x, 4);
}

TEST(UtilitsTest, MidlPointTest4)
{
    int a = 12;
    int b = 20;
    double x = midl_point(a, b);

    EXPECT_EQ(x, 4);
}

TEST(UtilitsTest, UmnohTest)
{
    size_t a = get_num<size_t>(1);
    size_t x = get_num<size_t>();
    size_t b = a * x;

    EXPECT_EQ(b, 20);
}
    