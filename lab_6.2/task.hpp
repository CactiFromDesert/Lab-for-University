#pragma once

#include <iostream>
#include <cstring>

template <typename T>
class Deque
{
private:
    T* data;
    int capacity;
    int front_idx;
    int back_idx;
    int size_val;

    void resize() {
        int new_capacity = capacity * 2;
        T* new_data = new T[new_capacity];
        
        for (int i = 0; i < size_val; i++) {
            new_data[i] = data[(front_idx + i) % capacity];
        }
        
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        front_idx = 0;
        back_idx = size_val - 1;
    }

public:
    Deque() : capacity(16), front_idx(0), back_idx(-1), size_val(0) {
        data = new T[capacity];
    }
    
    ~Deque() {
        delete[] data;
    }
    
    Deque(const Deque& other) : capacity(other.capacity), front_idx(0), back_idx(-1), size_val(0) {
        data = new T[capacity];
        for (int i = 0; i < other.size_val; i++) {
            push_back(other[i]);
        }
    }
    
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            data = new T[capacity];
            front_idx = 0;
            back_idx = -1;
            size_val = 0;
            for (int i = 0; i < other.size_val; i++) {
                push_back(other[i]);
            }
        }
        return *this;
    }
    
    void push_back(const T& value) {
        if (size_val == capacity) {
            resize();
        }
        back_idx = (back_idx + 1) % capacity;
        data[back_idx] = value;
        size_val++;
    }
    
    void push_front(const T& value) {
        if (size_val == capacity) {
            resize();
        }
        front_idx = (front_idx - 1 + capacity) % capacity;
        data[front_idx] = value;
        size_val++;
    }
    
    void pop_back() {
        if (size_val > 0) {
            back_idx = (back_idx - 1 + capacity) % capacity;
            size_val--;
        }
    }
    
    void pop_front() {
        if (size_val > 0) {
            front_idx = (front_idx + 1) % capacity;
            size_val--;
        }
    }
    
    T& front() {
        return data[front_idx];
    }
    
    const T& front() const {
        return data[front_idx];
    }
    
    T& back() {
        return data[back_idx];
    }
    
    const T& back() const {
        return data[back_idx];
    }
    
    T& operator[](int index) {
        return data[(front_idx + index) % capacity];
    }
    
    const T& operator[](int index) const {
        return data[(front_idx + index) % capacity];
    }
    
    int size() const {
        return size_val;
    }
    
    bool empty() const {
        return size_val == 0;
    }
    
    void clear() {
        front_idx = 0;
        back_idx = -1;
        size_val = 0;
    }
};

struct Point
{
    int x;
    int y;
    int id;
    
    Point() : x(0), y(0), id(-1) {}
    Point(int x_val, int y_val, int id_val) : x(x_val), y(y_val), id(id_val) {}
};

int orientation(const Point& A, const Point& B, const Point& C);

bool isPalindrome(const char* str);

//ФУНКЦИИ ДЛЯ АЛГОРИТМА ГРЭХЕМА

int findLeftmostPointIndex(const Deque<Point>& points);

bool comparePoints(const Point& pivot, const Point& a, const Point& b);

void movePointToFront(Deque<Point>& points, int idx);

void sortPointsByAngle(Deque<Point>& points);

Deque<Point> removeCollinearPoints(const Deque<Point>& points);

// АЛГОРИТМ ГРЭХЕМА 

Deque<Point> grahamScan(Deque<Point> points);

//Остальное

void printPoints(const Deque<Point>& points);

void addPoint(Deque<Point>& points, int x, int y);