#include "queue.hpp"

std::vector<size_t> hamming_number(size_t n)
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
}