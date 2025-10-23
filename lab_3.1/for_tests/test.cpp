#include <gtest/gtest.h>

#include "../utilits.hpp"
#include "../sort.hpp"

TEST(SortTest, BubbleTest1)
{
    int array[10] = {4,3,8,1,9,2,6,7,5,0};
    bubble(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i);
    }
}

TEST(SortTest, BubbleTest2)
{
    int array[10] = {0,5,5,0,5,0,0,5,5,0};
    bubble(array, 10);
    for(size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(array[i], 0);
    }
}

TEST(SortTest, BubbleTest3)
{
    int array[10] = {7,7,7,7,7,9,7,7,7,7};
    bubble(array, 10);
    
    EXPECT_EQ(array[9], 9);
    
}

TEST(SortTest, BubbleTest4)
{
    int array[10] = {22,20,24,21,26,23,25,27,29,28};
    bubble(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i + 20);
    }
}

TEST(SortTest, MergeTest1)
{
    int array[10] = {4,3,8,1,9,2,6,7,5,0};
    merge_sort(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i);
    }
}

TEST(SortTest, MergeTest2)
{
    int array[10] = {0,5,5,0,5,0,0,5,5,0};
    merge_sort(array, 10);
    for(size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(array[i], 0);
    }
}

TEST(SortTest, MergeTest3)
{
    int array[10] = {7,7,7,7,7,9,7,7,7,7};
    merge_sort(array, 10);
    
    EXPECT_EQ(array[9], 9);
    
}

TEST(SortTest, MergeTest4)
{
    int array[10] = {22,20,24,21,26,23,25,27,29,28};
    merge_sort(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i + 20);
    }
}

//count_sort
//Count

/*TEST(SortTest, CountTest1)
{
    char array[7] = {"cafbgde"};
    char array_2[7] = {"abcdefg"};
    count_sort(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], array_2[i]);
    }
}

TEST(SortTest, CountTest2)
{
    int array[10] = {0,5,5,0,5,0,0,5,5,0};
    merge_sort(array, 10);
    for(size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(array[i], 0);
    }
}

TEST(SortTest, CountTest3)
{
    int array[10] = {7,7,7,7,7,9,7,7,7,7};
    merge_sort(array, 10);
    
    EXPECT_EQ(array[9], 9);
    
}

TEST(SortTest, CountTest4)
{
    int array[10] = {22,20,24,21,26,23,25,27,29,28};
    merge_sort(array, 10);
    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(array[i], i + 20);
    }
}*/