#include <gtest/gtest.h>

#include "../utilits.hpp"
#include "../sort.hpp"

TEST(SortTest, FirstSortTest1)
{
    std::sort(array_1, array_1 + size, compare_first_sort);

    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i);
    }
}

TEST(SortTest, SecondSortTest1)
{
    
    std::sort(array_1, array_1 + size, compare_second_sort);

    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i);
    }
}