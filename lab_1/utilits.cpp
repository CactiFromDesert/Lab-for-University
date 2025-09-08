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
    midl = static_cast<double>(end - start)/2;
    return midl;
}