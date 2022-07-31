#ifndef QUEUE_H
#define QUEUE_H

#include "array_list.h"

#include <iostream>

class Queue
{
private:
    ArrayList *queue;

public:
    // Constructor
    Queue();

    // Getters
    int get_size() const;

    int peek() const;

    // Mutators
    void enqueue(int value);
    int dequeue();

    // Display
    friend std::ostream &operator<<(std::ostream &out, const Queue &queue);
    void display_info() const;
};

#endif
