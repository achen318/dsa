#include "queue.h"

// ----- Constructor -----
Queue::Queue()
{
    this->queue = new ArrayList;
}

// ----- Getters -----
int Queue::get_size() const
{
    return (this->queue)->get_size();
}

int Queue::peek() const
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
std::ostream &operator<<(std::ostream &out, const Queue &queue)
{
    out << '[';

    for (int i = 0; i < queue.get_size(); i++)
    {
        out << queue.queue->get(i);

        // If this is not the last element, add a separator
        if (i != queue.get_size() - 1)
            out << " | ";
    }

    out << ']';

    return out;
}

void Queue::display_info() const
{
    std::cout << "Queue - " << *this << '\n';
    std::cout << "Size  - " << this->get_size() << "\n\n";
}
