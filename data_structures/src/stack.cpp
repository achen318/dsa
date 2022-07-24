#include "stack.h"

#include <iostream>
#include <string>

// ----- Constructor -----
Stack::Stack()
{
    this->stack = new ArrayList;
}

// ----- Getters -----
int Stack::get_size()
{
    return (this->stack)->get_size();
}

int Stack::peek()
{
    ArrayList *stack = this->stack;
    const int last_index = stack->get_size() - 1;

    return stack->get(last_index);
}

// ----- Mutators -----
void Stack::push(int value)
{
    (this->stack)->add(value);
}

int Stack::pop()
{
    ArrayList *stack = this->stack;
    const int last_index = stack->get_size() - 1;

    return stack->remove(last_index);
}

// ----- Display -----
void Stack::display(int padding_len = 0)
{
    std::cout << "===\n";

    const std::string padding = std::string(padding_len, ' ');

    for (int i = 0; i < this->get_size(); i++)
        std::cout << padding << ' ' << (this->stack)->get(i) << '\n';

    std::cout << padding << "===\n";
}

void Stack::display_info()
{
    std::cout << "Stack - ";
    this->display(8);
    std::cout << "Size  - " << this->get_size() << "\n\n";
}
