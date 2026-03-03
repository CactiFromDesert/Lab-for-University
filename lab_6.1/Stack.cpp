#include "Stack.hpp"


void initDynamicStack(DynamicCharStack* stack, int& initialCapacity)
{
    stack->data = new char[initialCapacity];
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void resizeStack(DynamicCharStack* stack)
{
    int newCapacity = stack->capacity * 2;
    char* newData = new char[newCapacity];
    
    for (int i = 0; i <= stack->top; i++) {
        newData[i] = stack->data[i];
    }
    
    delete[] stack->data;
    stack->data = newData;
    stack->capacity = newCapacity;
}

bool isEmpty(DynamicCharStack* stack)
{
    return stack->top == -1;
}


void push(DynamicCharStack* stack, char ch)
{
    if (stack->top == stack->capacity - 1)
        resizeStack(stack);
    stack->data[++stack->top] = ch;
}

void pop(DynamicCharStack* stack)
{
    if (isEmpty(stack))
        throw std::underflow_error("Stack underflow!");
    stack->top--;
}


char top(DynamicCharStack* stack)
{
    if (isEmpty(stack))
        throw std::underflow_error("Stack is empty!");
    return stack->data[stack->top];
}

int size(DynamicCharStack* stack)
{
    return stack->top + 1;
}

int capacity(DynamicCharStack* stack)
{
    return stack->capacity;
}

void clear(DynamicCharStack* stack)
{
    stack->top = -1;
}

// Освобождение памяти
void destroyStack(DynamicCharStack* stack)
{
    delete[] stack->data;
    stack->data = nullptr;
    stack->top = -1;
    stack->capacity = 0;
}
