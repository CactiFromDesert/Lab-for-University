#pragma once

#include <iostream>
/*#include <queue>
#include <vector>
#include <algorithm>*/
#include <limits>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* front_ptr;
    Node* back_ptr;
    size_t size_val;
    
public:
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
    Queue() : front_ptr(nullptr), back_ptr(nullptr), size_val(0) {}
    
    ~Queue()
    {
        while (front_ptr != nullptr)
        {
            Node* temp = front_ptr;
            front_ptr = front_ptr->next;
            delete temp;
        }
    }
    
    void push(const T& value)
    {
        Node* new_node = new Node(value);
        if (front_ptr == nullptr) 
            front_ptr = back_ptr = new_node;
        else
        {
            back_ptr->next = new_node;
            back_ptr = new_node;
        }
        size_val++;
    }
    
    void pop()
    {
        if (front_ptr == nullptr) return;
        Node* temp = front_ptr;
        front_ptr = front_ptr->next;
        delete temp;
        size_val--;
        if (front_ptr == nullptr) 
            back_ptr = nullptr;
    }
    
    T& front()
    {
        return front_ptr->data;
    }
    
    const T& front() const
    {
        return front_ptr->data;
    }
    
    bool empty() const
    {
        return size_val == 0;
    }
    
    size_t size() const
    {
        return size_val;
    }
};

void printHammingNumbers(size_t n);

//std::vector<size_t> hamming_number(size_t n);

/*template <typename T>
T get_num(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
    T number;
    while (true)
    {
        std::cin >> number;
        if (std::cin.eof())
            throw std::runtime_error("It is EOF, sorry\n");
        
        else if (std::cin.bad())
            throw std::runtime_error("WTF?!\n");
        
        else if (std::cin.fail() || number < min || number > max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!\n";
        }
        else 
            return number;
    }
}*/