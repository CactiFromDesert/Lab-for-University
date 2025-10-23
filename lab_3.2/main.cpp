#include "utilits.hpp"
#include "sort.hpp"


int main()
{
    //std::cout << (-678 % 10 +10) % 10<< "\n";


    int* array_1 = nullptr;
    size_t size;
    try 
    {
        while (true)
        {
            std::cout << "\n";
            std::cout << "1. Input array\n\n" << "2. Output array\n\n" << "3. First sort\n\n" << "4. Second sort\n\n" << "5. Exit\n\n\n";
            int n = get_num<int>(0, 5);
            std::cout << "\n";
            switch(n)
            {
                case 1:
                {
                    free_array(array_1);
                    std::cout << "Enter the size of array\n\n";
                    size = get_num<size_t>(1, 1000);
                    array_1 = initialization(size);
                    std::cout << "Enter the array numbers\n";
                    input_array(array_1, size);
                    break;
                }
                case 2:
                {
                    if(!array_1 || !size)
                    {
                        std::cout << "Array not found. Try again\n\n";
                        break;
                    }
                    output_array(array_1, size);
                    break;
                }
                case 3:
                {
                    if(!array_1 || !size)
                    {
                        std::cout << "Array not found. Try again\n\n";
                        break;
                    }
                    std::sort(array_1, array_1 + size, compare_first_sort);
                    break;
                }
                case 4:
                {
                    if(!array_1 || !size)
                    {
                        std::cout << "Array not found. Try again\n\n";
                        break;
                    }
                    std::sort(array_1, array_1 + size, compare_second_sort);
                    break;
                }
                case 5:
                {
                    free_array(array_1);
                    return 0;
                    //break;
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
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    } 

    return 0;
}