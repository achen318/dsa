#ifndef STACK_H
#define STACK_H

#include "array_list.h"

class Stack
{
private:
    ArrayList *stack;

public:
    // Constructor
    Stack();

    // Getters
    int get_size();

    int peek();

    // Mutators
    void push(int value);
    int pop();

    // Display
    void display(int padding_len);
    void display_info();
};

#endif
