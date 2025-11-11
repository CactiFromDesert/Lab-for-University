#include "Person.hpp"

bool compare_name(const Person& p1, const Person& p2)
{
    return p1.name_ < p2.name_;
}

bool compare_surname(const Person& p1, const Person& p2)
{
    return p1.surname_ < p2.surname_;
}