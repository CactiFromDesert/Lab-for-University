#pragma once

#include <iostream>
#include <limits>

#include "utilits.hpp"

#include <iostream>

// noexcept   explicit

class Position
{
public:
    Position()noexcept: x_(0), y_(0) {}
    Position(double x, double y): x_(x), y_(y) {}

    Position& move(double x, double y);//как оператор +=

    double get_x() const noexcept;

    double get_y() const noexcept;

    // Position& set_x();   ????????????

private:
    double x_;
    double y_;
};

class Circle : virtual public Position
{
public:
    Circle() = delete;

    Circle(double r): Position(), r_(r) {}

    Circle(double x, double y, double r): Position(x, y), r_(r) {}

private:
    unsigned double r_;
};

class Square : virtual public Position
{
public:
    Square() = delete;

    Square(double len): Position(), len_(len) {}

    Square(double x, double y, double len): Position(x, y), len_(len) {}
    
private:
    unsigned double len_;
};

class CircleInSquare : public Circle, public Square
{
public:

private:
    
};