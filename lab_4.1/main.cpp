#include "task.hpp"
#include "utilits.hpp"

int main()
{
    try
    {
        std::cout << "\n\nEnter line\n";
        char* line = getline_cstyle();
    
        while (true)
        {
            std::cout << '\n';
            std::cout << "1. Palindrome check\n\n" << "2. Find substring\n\n" << "3. Find substring(array)\n\n" << "4. Ceasar cipher\n\n" << "5. Some out\n\n" << "6. Exit\n\n\n";
            int n = get_num<int>();
        
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << '\n';
            switch(n)
            {
                case 1:
                {
                    std::cout << palindrome(line);//Проверка на палиндром
                    std::cout << '\n';
                    break;
                }
                case 2:
                {
                    size_t number;
                    std::cout << "Enter a search string:\n";
                    char* line_2 = getline_cstyle();
                    std::cout << "Enter a start position:\n";
                    std::cin >> number;
                    std::cout << '\n';
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Position:  " << find_substring1(line, line_2, number) << '\n';//Z-функция
                    delete[] line_2;
                    break;
                }
                case 3:
                {
                    std::cout << "Enter a search string:\n";
                    char* line_4 = getline_cstyle();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    auto z_line = find_substring2(line, line_4);//Z-функция массив вхождений
                    std::cout << "Positions:  ";
                    for(size_t i = 0; i < z_line.second; ++i)
                    {
                        std::cout << z_line.first[i] << ' ';
                    }
                    std::cout << '\n';
                    delete[] z_line.first;
                    delete[] line_4;
                    break;
                }
                case 4:
                {
                    std::cout << "Enter the key\n\n";
                    int key = get_num<int>();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    ceasar(line, key);//шифр Цезаря
                    std::cout << "\nNew cipher: " << line << '\n';
                    break;
                }
                case 5:
                {
                    std::cout << "Enter a new line\n\n";
                    char* line_3 = getline_cstyle();
                    std::cout << '\n';
                    out_str(line_3);//Вывод си строки
                    delete[] line_3;
                    break;
                }
                case 6:
                {
                    delete[] line;// Очищение выделенной памяти
                    return 0;
                }
                default:
                    std::cout << "Try again\n";
            }
            delete[] line;
        }
        delete[] line;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}