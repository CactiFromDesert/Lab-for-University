#pragma once

#include <iostream>
#include <string>

#include "Less.hpp"

template<typename T, typename Compare = Less<T>>
void quick_sort(T arr[], size_t size, Compare comp = {}) 
{
    if (size <= 1) 
        return;

    T pivot = arr[size / 2];
    size_t i = 0, j = size - 1;

    while (i <= j) 
    {
        while (comp(arr[i], pivot))
            ++i;
        while (comp(pivot, arr[j]))
            --j;

        if (i <= j) 
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    quick_sort(arr, j + 1, comp);
    quick_sort(arr + i, size - i, comp);
}
