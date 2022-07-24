#include "queue.h"

#include <iostream>
#include <string>

// ----- Constructor -----
Queue::Queue()
{
    this->queue = new ArrayList;
}

// ----- Getters -----
int Queue::get_size()
{
    return (this->queue)->get_size();
}

int Queue::peek()
{
    return (this->queue)->get(0);
}

// ----- Mutators -----
void Queue::enqueue(int value)
{
    (this->queue)->add(value);
}

int Queue::dequeue()
{
    return (this->queue)->remove(0);
}

// ----- Display -----
void Queue::display(int padding_len)
{
    std::cout << "===\n";

    const std::string padding = std::string(padding_len, ' ');

    for (int i = 0; i < this->get_size(); i++)
        std::cout << padding << ' ' << (this->queue)->get(i) << '\n';

    std::cout << padding << "===\n";
}

void Queue::display_info()
{
    std::cout << "Queue - ";
    this->display(8);
    std::cout << "Size  - " << this->get_size() << "\n\n";
}
