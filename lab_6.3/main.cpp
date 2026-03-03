#include "queue.hpp"


int main() {
    size_t n;
    std::cout << "Введите количество чисел n: ";
    std::cin >> n;
    
    printHammingNumbers(n);
    
    return 0;
}

/*int main()
{
    std::cout << "\nEnter quanity Hammings number:  ";
    size_t num = get_num<size_t>(1);
    std::vector<size_t> v = hamming_number(num);
    std::cout << '\n';
    for(size_t i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}*/