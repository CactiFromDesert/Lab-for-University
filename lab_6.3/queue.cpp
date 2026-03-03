#include "queue.hpp"

/*std::vector<size_t> hamming_number(size_t n)
{
    std::vector<size_t> nums;
    std::queue<size_t> qu_2, qu_3, qu_5;
    nums.push_back(1);
    qu_2.push(2);
    qu_3.push(3);
    qu_5.push(5);
    for(size_t i = 1; i < n; ++i)
    {
        size_t min = std::min({qu_2.front(), qu_3.front(), qu_5.front()});
        nums.push_back(min);
        if(min == qu_2.front())
            qu_2.pop();
        if(min == qu_3.front())
            qu_3.pop();
        if(min == qu_5.front())
            qu_5.pop();
        qu_2.push(min*2);
        qu_3.push(min*3);
        qu_5.push(min*5);
    }
    return nums;
}*/

void printHammingNumbers(size_t n)
{
    if (n == 0) return;
    
    // Создаем три очереди
    Queue<size_t> q2, q3, q5;
    
    // Первое число - 1
    size_t next = 1;
    
    for (size_t count = 0; count < n; count++)
    {
        std::cout << next << " ";
        
        q2.push(next * 2);
        q3.push(next * 3);
        q5.push(next * 5);
        
        // Находим минимум
        size_t min_val = q2.front();
        if (q3.front() < min_val) min_val = q3.front();
        if (q5.front() < min_val) min_val = q5.front();
        
        next = min_val;
        
        // Удаляем минимум из всех очередей
        if (!q2.empty() && q2.front() == next) q2.pop();
        if (!q3.empty() && q3.front() == next) q3.pop();
        if (!q5.empty() && q5.front() == next) q5.pop();
    }

    std::cout << "\n";
}