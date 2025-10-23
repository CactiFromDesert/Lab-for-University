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

void merge_sort(int* array, size_t size)
{
    if(size <= 1)
    {
        return;
    }
    merge_sort_impl(array, 0, size - 1);
}

void merge_sort_impl(int* array, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort_impl(array, left, mid);
        merge_sort_impl(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(int* array, int left, int mid, int right)
{
    int n1 = mid - left +1;
    int n2 = right - mid;

    int L[n1], R[n2];

    std::copy(array + left, array + left + n1, L);
    std::copy(array + mid + 1, array + mid + 1 + n2, R);

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}