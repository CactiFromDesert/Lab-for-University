#pragma once

#include <iostream>
#include <limits>
#include <bitset>
#include <optional>

template <typename T>
T get_num(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
    T number;
    while (true)
    {
        std::cin >> number;
        if (std::cin.eof())
        {
            throw std::runtime_error("It is EOF, sorry\n");
        }
        else if (std::cin.bad())
        {
            throw std::runtime_error("WTF?!\n");
        }
        else if (std::cin.fail() || number < min || number > max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!\n";
        }
        else 
            return number;
    }
}

double midl_point(int& start, int& end);

void function_for_first_task();

void function_for_second_task();

void function_for_third_task();

void function_for_fourth_task();

