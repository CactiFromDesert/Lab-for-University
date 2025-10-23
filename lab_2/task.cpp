#include "task.hpp"


void f_triangle(const size_t num)
{
    for(size_t i = 0; i <= num; ++i)
    {
        for(size_t k = 0; k <= i; ++k)
        {
            std::cout << k << ' ';
        }
        std::cout << '\n';
    }
}

size_t factorial(size_t num)
{
    if(num == 1 || num == 0)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

void f_factorial(const size_t num)
{
    double c;
    double n = static_cast<double>(num);
    for(double k = 0; k <= n; ++k)
    {
        c = static_cast<double>(factorial(n)/(factorial(n - k) * factorial(k)));
        std::cout << c << ' ';
    }
    std::cout << '\n';
}

double arit_mean(size_t quan, double sum)
{
    if(quan == 0 || sum == 0)
        return 0;
    return sum/static_cast<double>(quan);
}

void f_arithmetic()
{
    char meaning = '\n\n';
    size_t quan = 0;
    double sum = 0;
    std::cout << "Enter a number or 'e' for end enter:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    while(std::cin >> quan)
    {
        sum +=static_cast<double>(quan);
        ++quan;
        if(static_cast<char>(quan) == meaning)
            break;
    } 
    std::cout << "\nArithmetic mean:  " << arit_mean(quan, sum) << '\n';
}

/*void f_arithmetic()
{
    char meaning;
    size_t quan = 0;
    double sum = 0;
    std::cout << "Enter a number or 'e' for end enter:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    while(std::cin >> quan)
    {
        sum +=static_cast<double>(quan);
        ++quan;
        //if(meaning == 'e')
            //break;
    }
    std::cout << "Arithmetic mean:  " << arit_mean(quan, sum) << '\n';
}*/