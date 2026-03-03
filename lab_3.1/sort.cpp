#include "sort.hpp"
#include "utilits.hpp"


void bubble(int* arr, size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t x = i + 1; x < size ; ++x)
        {
            if (arr[i] > arr[x])
            {
                std::swap(arr[i], arr[x]);
            }
        }
    }
}

void count_sort(char* array, size_t size)
{
    try 
    {
        char min = *std::min_element(array, array + size); 
        char max = *std::max_element(array, array + size); 
        int range = max - min + 1;

        char *count = new char[range](), *output = new char[size];

        for (size_t i = 0; i < size; ++i) 
            ++count[array[i] - min];

        for (int i = 1; i < range; ++i) 
            count[i] += count[i - 1];

        for (int i = static_cast<int>(size) - 1; i >= 0; --i) 
        {
            output[count[array[i] - min] - 1] = array[i];
            count[array[i] - min]--;
        }

        std::copy(output, output + size, array);
        delete[] count;
        delete[] output;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';//!!!!!!!!!!!!!!!!!
    }
}

.