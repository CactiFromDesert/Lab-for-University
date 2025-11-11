#include "sort.hpp"



int main()
{
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t intSize = sizeof(intArr) / sizeof(intArr[0]);
    quick_sort(intArr, intSize);
    for(int elem : intArr)
        std::cout << elem;

    return 0;
}
