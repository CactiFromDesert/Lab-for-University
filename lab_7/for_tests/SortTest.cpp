#include <gtest/gtest.h>

#include "../sort.hpp"

TEST(SortTest, SortDefaultTestWithInt)
{
    int arr[10] = {3, -34, -1000, 456, 6, 764, 0, -22, 89, 12345};
    int arr2[10] = {-1000, -34, -22, 0, 3, 6, 89, 456, 764, 12345};

    quick_sort(arr, 10);

    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_EQ(arr[i], arr2[i]);
    }
}

TEST(SortTest, SortGreaterTestWithInt)
{
    int* arr = new int[10]{3, -34, -1000, 456, 6, 764, 0, -22, 89, 12345};
    int arr2[10] = {-1000, -34, -22, 0, 3, 6, 89, 456, 764, 12345};

    quick_sort(arr, 10, std::greater<int>());

    for(size_t i = 0, j = 9; i < 10; ++i, --j)
    {
        EXPECT_EQ(arr[i], arr2[j]);
    }
    delete[] arr;
}

TEST(SortTest, SortDefaultTestWithDouble)
{
    double* arr = new double[5]{3.444, -34.87, -1000.4, 456, 6};
    double arr2[5] = {-1000.4, -34.87, 3.444, 6, 456};

    quick_sort(arr, 5);

    for(size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(arr[i], arr2[i]);
    }
    delete[] arr;
}

TEST(SortTest, SortGreaterTestWithDouble)
{
    double* arr = new double[5]{3.444, -34.87, -1000.4, 456, 6};
    double arr2[5] = {-1000.4, -34.87, 3.444, 6, 456};

    quick_sort(arr, 5, std::greater<double>());

    for(size_t i = 0, j = 4; i < 5; ++i, --j)
    {
        EXPECT_EQ(arr[i], arr2[j]);
    }
    delete[] arr;
}

TEST(SortTest, SortDefTestWithStr)
{
    
    std::string names[] = {
        "Ivan", "Anna", "Petr", "Maria", "Alexey",
        "Olga", "Dmitry", "Elena", "Sergey", "Natalia"
    };
    std::string res[] = {"Alexey","Anna","Dmitry","Elena","Ivan","Maria"
        ,"Natalia","Olga","Petr","Sergey"};

    quick_sort(names, 10);

    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_STREQ(names[i].c_str(), res[i].c_str());
    }
}

TEST(SortTest, SortDefTestWithPerson)
{
    Person people[] = {
        Person("Ivanov", "Ivan", 25),
        Person("Petrova", "Anna", 30),
        Person("Sidorov", "Alexey", 20),
        Person("Kozlova", "Maria", 35),
        Person("Smirnov", "Dmitry", 28),
        Person("Volkova", "Olga", 22),
        Person("Orlov", "Sergey", 40),
        Person("Lebedeva", "Elena", 26),
        Person("Morozov", "Andrey", 32),
        Person("Zaytseva", "Natalia", 19)
    };

    Person expected_sorted_by_age_asc[] = {
        Person("Zaytseva", "Natalia", 19),
        Person("Sidorov", "Alexey", 20),
        Person("Volkova", "Olga", 22),
        Person("Ivanov", "Ivan", 25),
        Person("Lebedeva", "Elena", 26),
        Person("Smirnov", "Dmitry", 28),
        Person("Petrova", "Anna", 30),
        Person("Morozov", "Andrey", 32),
        Person("Kozlova", "Maria", 35),
        Person("Orlov", "Sergey", 40)
    };

    quick_sort(people, 10);

    for(size_t i = 0; i < 10; ++i)
    {
        EXPECT_TRUE(people[i] == expected_sorted_by_age_asc[i]);
    }
}