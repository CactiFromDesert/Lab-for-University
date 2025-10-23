#include "task.hpp"
#include "utilits.hpp"

int main()
{
    try
    {
        while (true)
        {
            std::cout << '\n';
            std::cout << "1. Number triangle\n\n" << "2. Binomial coefficients\n\n" << "3. Arithmetic mean\n\n" << "4. Exit\n\n";
            int n = get_num<int>(0, 4);
            std::cout << '\n';
            switch(n)
            {
                case 1:
                {
                    //Числовой треугольник
                    std::cout << "Enter integer (<20): \n\n";
                    size_t number = get_num<size_t>(0, 20); //до 20 я написала ограничение
                    std::cout << '\n';
                    f_triangle(number);

                    break;
                }
                case 2:
                {
                    //Коэффициенты
                    std::cout << "Enter number: \n\n";
                    size_t number = get_num<size_t>(0, 100);
                    std::cout << '\n';
                    f_factorial(number);

                    break;
                }
                case 3:
                {
                    //Сред. арифмитическое
                    f_arithmetic();

                    break;
                }
                case 4:
                {
                    return 0;
                }
                default:
                    std::cout << "Try again\n";
            }
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}