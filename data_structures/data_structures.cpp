#include "array_list.h"

#include <iostream>

void test_array_list()
{
    std::cout << "----- ArrayList -----" << '\n';

    // Create an array list
    constexpr int size = 3;
    ArrayList array_list;

    // Fill the array list with values between 1 and size
    for (int i = 1; i <= size; i++)
    {
        array_list.add(i);
        array_list.display_info();
    }

    // Test add() and remove()
    for (int i = 0; i < size; i++)
    {
        array_list.add(i, 0);
        array_list.display_info();

        array_list.remove(i);
        array_list.display_info();
    }
}

int main()
{
    test_array_list();

    return 0;
}
