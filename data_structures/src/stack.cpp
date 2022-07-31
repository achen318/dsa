#include "stack.h"

// ----- Constructor -----
Stack::Stack()
{
    this->stack = new ArrayList;
}

// ----- Getters -----
int Stack::get_size() const
{
    return (this->stack)->get_size();
}

int Stack::peek() const
{
    ArrayList *stack = this->stack;
    const int last_index = stack->get_size() - 1;

    return (*stack)[last_index];
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
std::ostream &operator<<(std::ostream &out, const Stack &stack)
{
    out << '[';

    for (int i = 0; i < stack.get_size(); i++)
    {
        out << (*stack.stack)[i];

        // If this is not the last element, add a separator
        if (i != stack.get_size() - 1)
            out << " | ";
    }

    out << ']';

    return out;
}

void Stack::display_info() const
{
    std::cout << "Stack - " << *this << '\n';
    std::cout << "Size  - " << this->get_size() << "\n\n";
}
