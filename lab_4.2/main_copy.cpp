#include "task.hpp"
#include "utilits.hpp"

///home/where/Lab_University/lab_4.2/main.cpp

/*std::string file_format(std::string file_path_full) 
{
    int pos = file_path_full.find_first_of("/\\:*?\"<>|")
    if (pos == std::string::npos)
    {
        return "error";
    }
    return file_path_full.substr(pos,-1);
}*/

int main()
{
    //необходима доп компиляция версии ++17
    std::string str;
    std::cout << "Enter the file\n";
    std::getline(std::cin, str);
    
    try 
    {
        while (true)
        {
            std::cout << '\n';
            std::cout << "1. Get extension\n\n" << "2. Get name\n\n" << "3. Get location\n\n" << "4. Get name_disk\n\n" << "5. Rename file\n\n" << "6. Copy file\n\n" << "7. Exit\n\n\n";
            int n = get_num<int>(0, 7);
            std::cout << '\n';
            switch(n)
            {
                case 1:
                {
                    // выводит расширение
                    auto file = file_format(str);
                    if(file.has_value())
                    {
                        std::cout << file.value();
                        std::cout << '\n';
                        break;
                    }
                    else
                    {
                        std::cout << "Error! Try again\n";
                        break;
                    }
                }
                case 2:
                {
                    // выводит имя файла
                    
                    auto file = file_name(str);
                    if(file.has_value())
                    {
                        std::cout << file.value();
                        std::cout << '\n';
                        break;
                    }
                    else
                    {
                        std::cout << "Error! Try again\n";
                        break;
                    }
                }
                case 3:
                {
                    // выводит расположение
                    
                    auto file = file_path(str);
                    if(file.has_value())
                    {
                        std::cout << file.value();
                        std::cout << '\n';
                        break;
                    }
                    else
                    {
                        std::cout << "Error! Try again\n";
                    }
                    break;
                }
                case 4:
                {
                    // выводит диск
                    
                    auto file = file_disk(str);
                    if(file.has_value())
                    {
                        std::cout << file.value();
                        std::cout << '\n';
                    }
                    else
                    {
                        std::cerr << "Error! Try again\n";
                    }
                    break;
                }
                case 5:
                {
                    // переименование файла
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    file_rename(str);
                    //std::cout << str;
                    std::cout << '\n';
                    break;
                }
                case 6:
                {
                    // создание копии
                    
                    file_copy(str);
                    std::cout << '\n';
                    break;
                }
                case 7:
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
