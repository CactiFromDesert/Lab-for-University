#include <iostream>
#include <stdexcept>
#include <cstring>


struct DynamicCharStack
{
    char* data;
    int top;
    int capacity;
};

void initDynamicStack(DynamicCharStack* stack, int& initialCapacity);

void resizeStack(DynamicCharStack* stack);

bool isEmpty(DynamicCharStack* stack);


void push(DynamicCharStack* stack, char ch);

void pop(DynamicCharStack* stack);


char top(DynamicCharStack* stack);

int size(DynamicCharStack* stack);

int capacity(DynamicCharStack* stack);

void clear(DynamicCharStack* stack);

// Освобождение памяти
void destroyStack(DynamicCharStack* stack);