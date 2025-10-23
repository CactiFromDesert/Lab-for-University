#include "utilits.hpp"

int main()
{
    std::cout << "\n\nSorokina Alina Igorevna 251-372\n\n";
    try
    {
        while (true)
        {
            std::cout << '\n';
            std::cout << "1. First task\n\n" << "2. Second task\n\n" << "3. Third task\n\n" << "4. Fourth task\n\n" << "5. Exit\n\n\n";
            int n = get_num<int>(0, 6);
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << '\n';
            switch(n)
            {
                case 1:
                {
                    function_for_first_task();
                    break;
                }
                case 2:
                {
                    function_for_second_task();
                    break;
                }
                case 3:
                {
                    function_for_third_task();
                    break;
                }
                case 4:
                {
                    function_for_fourth_task();
                    break;
                }
                case 5:
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


    