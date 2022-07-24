#ifndef QUEUE_H
#define QUEUE_H

#include "array_list.h"

class Queue
{
private:
    ArrayList *queue;

public:
    // Constructor
    Queue();

    // Getters
    int get_size();

    int peek();

    // Mutators
    void enqueue(int value);
    int dequeue();

    // Display
    void display(int padding_len);
    void display_info();
};

#endif
