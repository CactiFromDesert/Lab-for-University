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
    Circle() = default;

    Circle(double r): Position(), r_(r) {}
    {
        std::cout << "Circle";
    }

    Circle(double x, double y, double r): Position(x, y), r_(r) {ё}
    

private:
    double r_;
};

class Square : virtual public Position
{
public:
    Square() = default;

    Square(double len): Position(), len_(len) {}
    {
        std::cout << "Square";
    }

    Square(double x, double y, double len): Position(x, y), len_(len) {}
    
    
private:
    double len_;
};

class CircleInSquare : public Circle, public Square
{
public:
    //CircleInSquare() = delete;

    CircleInSquare(double len): r_(len / 2), len_(len) {}

    CircleInSquare(double x, double y, double len): Position(x, y), r_(len / 2), len_(len) 
    {
        std::cout << "\nCircleInSquare\n";
    }

};