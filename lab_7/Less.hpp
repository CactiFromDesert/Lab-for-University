#pragma once

#include "Person.hpp"

template<typename T>
struct Less
{
    bool operator()(const T& op1, const T& op2) const
    {
        return op1 < op2;
    }
};

template<>
struct Less<Person>
{
    bool operator()(const Person& op1, const Person& op2) const
    {
        return op1.age_ < op2.age_;
    }
};