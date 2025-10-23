#include "sort.hpp"
#include "utilits.hpp"

int main()
{
    try
    {
        while (true)
        {
            std::cout << "\n";
            std::cout << "1. Bubble sort\n\n" << "2. Count sort\n\n" << "3. Merge sort\n\n" << "4. Exit\n\n\n";
            int n = get_num<int>(0, 4);
            std::cout << "\n";
            switch(n)
            {
                case 1:
                {
                    int array[SIZE];
                    std::cout << "Enter the size of array 1 <= x <= 1000\n\n";
                    size_t size = get_num<size_t>(0, 1000);
                    std::cout << "Enter the array numbers:\n";
                    input_array(array, size);
                    bubble(array, size);
                    out_array(array, size);
                    break;
                }
                case 2:
                {
                    char array[SIZE];
                    std::cout << "Enter the size of array 1 <= x <= 1000\n\n";
                    size_t size = get_num<size_t>(0, 1000);
                    std::cout << "Enter the array numbers:\n";
                    input_array(array, size);
                    count_sort(array, size);
                    out_array(array, size);
                    break;
                }
                case 3:
                {
                    int array[SIZE];
                    std::cout << "Enter the size of array 1 <= x <= 1000\n\n";
                    size_t size = get_num<size_t>(0, 1000);
                    std::cout << "Enter the array numbers:\n";
                    input_array(array, size);
                    merge_sort(array, size);
                    out_array(array, size);
                    break;
                }
                case 4:
                {
                    return 0;
                }
                default:
                    std::cout << "Try again\n";
                    break;
            }
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}