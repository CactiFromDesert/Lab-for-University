#include "queue.hpp"

int main()
{
    std::cout << "\nEnter quanity Hammings number:  ";
    size_t num = get_num<size_t>(1);
    std::vector<size_t> v = hamming_number(num);
    std::cout << '\n';
    for(size_t i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}