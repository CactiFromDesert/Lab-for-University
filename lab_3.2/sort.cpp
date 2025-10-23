#include "sort.hpp"
#include "utilits.hpp"

int summ_p(int a)
{
    if(a < 0)
    {
        a *= (-1);
    }
    size_t s = 0, n = 0;
    if(count_p(a) % 2 != 0)
    {
        ++n;
    }
    while(a > 0)
    {
        size_t b = a % 10;
        a = a / 10;
        if( n % 2 == 0)
        {
            s += b;
        }
        ++n;
    }
    return s;
}

size_t count_p(int a)
{
    size_t n = 0;
    while(a > 0)
    {
        a = a / 10;
        ++n;
    }
    return n;
}

bool compare_first_sort( int a, int b)
{
    return summ_p(a) < summ_p(b);
}

bool compare_second_sort( int a, int b)
{
    if((std::abs(a) % 10) != (std::abs(b) % 10))
    {
        return (std::abs(a) % 10) < (std::abs(b) % 10);
    }
    return a > b;
}

