#include "utilits.hpp"


void out_array(int* array, size_t size)
{
    std::cout << "\n\n";
    for(size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
}

void input_array(int* array, size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = get_num<int>();
    }
}

void input_array(char* array, size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        /*unsigned short a =  get_num<unsigned short>(0, 255);
        array[i] = static_cast<char>(a);*/
        array[i] = get_num<char>(97, 122);
    }
}

void out_array(char* array, size_t size)
{
    std::cout << "\n\n";
    for(size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
}

