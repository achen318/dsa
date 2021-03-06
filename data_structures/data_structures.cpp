#include "array_list.h"
#include "hash_map.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

#include <iostream>

void test_array_list(int size)
{
    std::cout << "----- ArrayList -----" << '\n';

    // Create an array list
    ArrayList array_list;
    array_list.display_info();

    // Fill the array list with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        array_list.add(i);
        array_list.display_info();
    }

    // Test operator[] and remove()
    for (int i = 0; i < size; i++)
    {
        array_list[0] = 2 * (i + 1);
        array_list.display_info();

        array_list.remove(0);
        array_list.display_info();
    }
}

void test_hash_map(int size)
{
    std::cout << "----- HashMap -----" << '\n';

    // Create a hash map
    HashMap hash_map;
    hash_map.display_info();

    // Fill the hash map with key/value pairs of (1, 1) to (size, size)
    for (int i = 1; i <= size; i++)
    {
        hash_map.add(i, i);
        hash_map.display_info();
    }

    // Test set() and remove()
    for (int i = 1; i <= size; i++)
    {
        hash_map.set(i, 2 * i);
        hash_map.display_info();

        hash_map.remove(i);
        hash_map.display_info();
    }
}

void test_linked_list(int size)
{
    std::cout << "----- LinkedList -----" << '\n';

    // Create a linked list
    LinkedList linked_list;
    linked_list.display_info();

    // Fill the linked list with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        linked_list.add(i);
        linked_list.display_info();
    }

    // Test operator[] and remove()
    for (int i = 0; i < size; i++)
    {
        linked_list[0] = 2 * (i + 1);
        linked_list.display_info();

        linked_list.remove(0);
        linked_list.display_info();
    }
}

void test_queue(int size)
{
    std::cout << "----- Queue -----" << '\n';

    // Create a queue
    Queue queue;
    queue.display_info();

    // Fill the queue with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        queue.enqueue(i);
        queue.display_info();
    }

    // Test enqueue() and dequeue()
    for (int i = 0; i <= size; i++)
    {
        queue.enqueue(i);
        queue.display_info();

        queue.dequeue();
        queue.display_info();
    }
}

void test_stack(int size)
{
    std::cout << "----- Stack -----" << '\n';

    // Create a stack
    Stack stack;
    stack.display_info();

    // Fill the stack with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        stack.push(i);
        stack.display_info();
    }

    // Test push() and pop()
    stack.push(0);
    stack.display_info();

    stack.pop();
    stack.display_info();
}

int main()
{
    constexpr int size = 5;

    test_array_list(size);
    test_hash_map(size);
    test_linked_list(size);
    test_queue(size);
    test_stack(size);

    return 0;
}
