#include "utilits.hpp"

double midl_point(int& start, int& end)
{
    double f;
    double midl;
    if(start < 0 && end >= 0)
    {
        f = start * (-1);
        midl = start + (static_cast<double>(f + end)/2);
        return midl;
    }
    if(start < 0 && end < 0)
    {
        midl = static_cast<double>(start + end)/2;
        return midl;
    }
    midl = static_cast<double>(end + start)/2;
    return midl;
}

void function_for_first_task()
{
    //std::cout << "Integer type:\n";
    std::cout << "int :" << std::numeric_limits<int>::min() << ' ' << std::numeric_limits<int>::max() << '\n';
    std::cout << "unsigned :" << std::numeric_limits<unsigned>::min() << ' ' << std::numeric_limits<unsigned>::max() << '\n';
    std::cout << "short :" << std::numeric_limits<short>::min() << ' ' << std::numeric_limits<short>::max() << '\n';
    std::cout << "long :" << std::numeric_limits<long>::min() << ' ' << std::numeric_limits<long>::max() << '\n';
    std::cout << "long long :" << std::numeric_limits<long long>::min() << ' ' << std::numeric_limits<long long>::max() << '\n';
    //std::cout << "Logical type:\n";
    std::cout << "bool :" << std::numeric_limits<bool>::min() << ' ' << std::numeric_limits<bool>::max() << '\n';
    //std::cout << "Character type:\n";
    std::cout << "char :" << static_cast<int>(std::numeric_limits<char>::min()) << ' ' << static_cast<int>(std::numeric_limits<char>::max()) << '\n';
    //std::cout << "Floating point nubers:\n";
    std::cout << "float :" << std::numeric_limits<float>::min() << ' ' << std::numeric_limits<float>::max() << '\n';
    std::cout << "double:" << std::numeric_limits<double>::min() << ' ' << std::numeric_limits<double>::max() << '\n';
    std::cout << "long double:" << std::numeric_limits<long double>::min() << ' ' << std::numeric_limits<long double>::max() << '\n';
    //std::cout << "Unsigned type:\n";
    std::cout << "unsigned int :" << std::numeric_limits<unsigned int>::min() << ' ' << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "unsigned char :" << static_cast<int>(std::numeric_limits<unsigned char>::min()) << ' ' << static_cast<int>(std::numeric_limits<unsigned char>::max()) << '\n';
    std::cout << "unsigned long :" << std::numeric_limits<unsigned long>::min() << ' ' << std::numeric_limits<unsigned long>::max() << '\n';
    std::cout << "unsigned long long(size_t) :" << std::numeric_limits<unsigned long long>::min() << ' ' << std::numeric_limits<unsigned long long>::max() << '\n';
}

void function_for_second_task()
{
    std::cout << "\nEnter a number:\n";
    double number = get_num<double>();
    std::cout << "Hex number:  " << std::hex << number;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::cout << "\nBinary number:  "; << std::bitset<32>(number) << number;
    /*for(int i = sizeof(number) * 8 - 1; i >= 0; --i) 
    {
        std::cout << ((static_cast<int>(number) >> i) & 1);
    }*/
    std::cout << "\nBinary number:  " << std::bitset<32>(number);
    std::cout << '\n';

    std::cout << static_cast<int>(number) << '\n';
    std::cout << static_cast<short>(number) << '\n';
    std::cout << static_cast<bool>(number) << '\n';
    std::cout << static_cast<long>(number) << '\n';
    std::cout << static_cast<long long>(number) << '\n';
    std::cout << static_cast<char>(number) << '\n';
    /*std::cout << static_cast<unsigned int>(number) << '\n';
    std::cout << static_cast<unsigned long>(number) << '\n';
    std::cout << static_cast<unsigned long long>(number) << '\n';
    std::cout << static_cast<unsigned char>(number) << '\n';*/
}

void function_for_third_task()
{
    std::cout << "\nEnter a number for a: \n";
    double a = get_num<double>();
    std::cout << "Enter a number for b: \n";
    double b = get_num<double>();
    if(a != 0)
    {
        double x = b / a;
        std::cout << " x =  " /*<< b << ' / ' << a*/ << x << '\n';
        //std::cout << " x =  " << std::dec << b << '\n';
    }
    
}

void function_for_fourth_task()
{
    std::cout << "\nEnter a start point and end point:\n";
    int start = get_num<int>(-100, 100);
    std::cout << '\n';
    int end = get_num<int>(-100, 100);
    if(end <= start)
    {
        std::cout << "Try again!!Enter a and point again\n";
        end = get_num<int>(-100, 100);
    }
    double midl = midl_point(start, end);
    std::cout << midl << '\n';
}


