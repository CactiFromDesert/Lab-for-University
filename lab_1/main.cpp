#include "utilits.hpp"

int main()
{
    //Задание первое
    std::cout << "\n\nSorokina Alina Igorevna 251-372\n\n\n";

    //Задание второе
    //std::cout << "Integer type:\n";
    std::cout << "int :" << std::numeric_limits<int>::min() << " " << std::numeric_limits<int>::max() << '\n';
    std::cout << "unsigned :" << std::numeric_limits<unsigned>::min() << " " << std::numeric_limits<unsigned>::max() << '\n';
    std::cout << "short :" << std::numeric_limits<short>::min() << " " << std::numeric_limits<short>::max() << '\n';
    std::cout << "long :" << std::numeric_limits<long>::min() << " " << std::numeric_limits<long>::max() << '\n';
    std::cout << "long long :" << std::numeric_limits<long long>::min() << " " << std::numeric_limits<long long>::max() << '\n';
    //std::cout << "Logical type:\n";
    std::cout << "bool :" << std::numeric_limits<bool>::min() << " " << std::numeric_limits<bool>::max() << '\n';
    //std::cout << "Character type:\n";
    std::cout << "char :" << std::numeric_limits<char>::min() << " " << std::numeric_limits<char>::max() << '\n';
    //std::cout << "Floating point nubers:\n";
    std::cout << "float :" << std::numeric_limits<float>::min() << " " << std::numeric_limits<float>::max() << '\n';
    std::cout << "double:" << std::numeric_limits<double>::min() << " " << std::numeric_limits<double>::max() << '\n';
    std::cout << "long double:" << std::numeric_limits<long double>::min() << " " << std::numeric_limits<long double>::max() << '\n';
    //std::cout << "Unsigned type:\n";
    std::cout << "unsigned int :" << std::numeric_limits<unsigned int>::min() << " " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "unsigned char :" << std::numeric_limits<unsigned char>::min() << " " << std::numeric_limits<unsigned char>::max() << '\n';
    std::cout << "unsigned long :" << std::numeric_limits<unsigned long>::min() << " " << std::numeric_limits<unsigned long>::max() << '\n';
    std::cout << "unsigned long long(size_t) :" << std::numeric_limits<unsigned long long>::min() << " " << std::numeric_limits<unsigned long long>::max() << '\n';


    //Задание третье
    std::cout << "First task:Enter a number:\n";
    double number = get_num<double>();
    std::cout << "Hex number:  " << std::hex << number;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::cout << "Binary number:  " << std::bitset << number;

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

    //Задание четвертое
    std::cout << "Second task:Enter a number for a: \n";
    size_t a = get_num<size_t>(1);
    std::cout << "Enter a number for x: \n";
    size_t x = get_num<size_t>();
    size_t b = a * x;
    std::cout << "a * x =  " << b << '\n';//выводит в хексе почему-то
    
    //Заданаие пятое
    std::cout << "Third task:Enter a start point and end point:\n";
    int start = get_num<int>(-100, 100);
    std::cout << '\n';
    int end = get_num<int>(-100, 100);
    if(end <= start)
    {
        std::cout << "Try again!!\n";
        end = get_num<int>(-100, 100);
    }
    double midl = midl_point(start, end);
    std::cout << midl << '\n';

    return 0;
}