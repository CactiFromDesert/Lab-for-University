#include <gtest/gtest.h>

#include "../task.hpp"
#include "../utilits.hpp"

/*TEST(TaskTest, TriangleTest)
{
    sise_t num = 4;
    size_t bag = 0;
    const char* str;
    while(bag != num)
    {
        //str.push_back(bag);
        std::cout << str << '\n';
        ++bag;
    }
}*/

/*TEST(TaskTest, TriangleTest)
{
    sise_t num = 4;
    size_t bag = 0;
    std::string str;
    while(bag != num)
    {
        //str.push_back(bag);
        std::cout << str << '\n';
        ++bag;
    }
}*/

/*TEST(TaskTest, FactorialTest)
{
    size_t num = 5;
    size_t a = factorial(num);
    EXPECT_EQ(a, 120);
}

TEST(TaskTest, FactorialTest1)
{
    size_t num = 3;
    size_t a = factorial(num);
    EXPECT_EQ(a, 6);
}

TEST(TaskTest, FactorialTest2)
{
    size_t num = 7;
    size_t a = factorial(num);
    EXPECT_EQ(a, 5040);
}*/

/*TEST(TaskTest, ArifmTest1)
{
    double a = arit_mean(5, 66);
    //std::cout << a;
    EXPECT_EQ(a, 13.2);
}

TEST(TaskTest, ArifmTest2)
{
    double a = arit_mean(4, 74);
    //std::cout << a;
    EXPECT_EQ(a, 18.5);
}*/

/*TEST(TaskTest, FunctionTest1)
{
    char meaning;
    size_t quan = 0;
    double sum = 0;
    std::cout << "Enter a number or 'e' for end enter:\n";
    while(meaning != 'e')
    {
        std::cin >> meaning;
        if(meaning != 'e')
        {
            sum += static_cast<double>(meaning % 48);
            ++quan;
        }
    }
    std::cout << sum;
}*/




TEST(TaskTest, cvbhjTest)
{
    int x = 6, y= 7;

    std::cout << x+y / 2;
}

TEST(TaskTest, cvbhjTest1)
{
    double x = 6, y= 7;

    std::cout << x+y / 2;
}