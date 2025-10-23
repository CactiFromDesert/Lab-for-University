#include "matrix.hpp"
#include "utilits.hpp"

int main()
{
    int* arr = new int [25]();
    std::fill_n(arr, 25, 9);
    Matrix<int> mat(5, 5, arr);

    std::cout << mat;


    return 0;
}