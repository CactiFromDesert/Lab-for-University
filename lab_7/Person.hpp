#pragma once

#include <string>
#include <iostream>

struct Person
{
    Person(const std::string& surname, const std::string& name, size_t age): surname_(surname), name_(name), age_(age) {}

    std::string surname_;
    std::string name_;
    size_t age_;

    bool operator==(const Person& peop) const noexcept
    {
        return surname_ == peop.surname_ && name_ == peop.name_ && age_ == peop.age_;
    }
};

bool compare_name(const Person& p1, const Person& p2);

bool compare_surname(const Person& p1, const Person& p2);