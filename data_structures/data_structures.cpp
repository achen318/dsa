#include "array_list.h"
#include "linked_list.h"

#include <iostream>

void test_array_list(int size)
{
    std::cout << "----- ArrayList -----" << '\n';

    // Create an array list
    ArrayList array_list;

    // Fill the array list with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        array_list.add(i);
        array_list.display_info();
    }

    // Test add() and remove()
    for (int i = 0; i <= size; i++)
    {
        array_list.add(i, 0);
        array_list.display_info();

        array_list.remove(i);
        array_list.display_info();
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

    // Test add() and remove()
    for (int i = 0; i <= size; i++)
    {
        linked_list.add(i, 0);
        linked_list.display_info();

        linked_list.remove(i);
        linked_list.display_info();
    }
}

int main()
{
    constexpr int size = 3;

    test_array_list(size);
    test_linked_list(size);

    return 0;
}
