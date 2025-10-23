#include "utilits.hpp"

int* initialization(size_t number)
{
    if(number < std::numeric_limits<size_t>::min() || number > std::numeric_limits<size_t>::max())
    {
        throw std::bad_alloc();
    }
    int* array = new int [number];
    return array;  
}

void input_array(int* array, size_t size)
{
    for(size_t i = 0; i < size; ++i )
    {
        std::cin >> array[i];
    }
}

void output_array( const int* array, size_t size)
{
    for(size_t i = 0; i < size; ++i )
    {
        std::cout << array[i] << ' ';
    }
    std::cout << "\n";
}

void free_array(int* array)
{
    delete[] array;
}

