#ifndef STACK_H
#define STACK_H

#include "array_list.h"

#include <iostream>

class Stack
{
private:
    ArrayList *stack;

public:
    // Constructor
    Stack();

    // Getters
    int get_size() const;

    int peek() const;

    // Mutators
    void push(int value);
    int pop();

    // Display
    friend std::ostream &operator<<(std::ostream &out, const Stack &stack);
    void display_info() const;
};

#endif
