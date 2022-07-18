#include "helper_functions.h"

#include <iostream>

void swap(int *arr, int a, int b)
{
    // Swap the values at the given indices if the indices are different
    if (a != b)
    {
        const int temp = arr[a];

        arr[a] = arr[b];
        arr[b] = temp;
    }
}

int mid_point(int start, int end)
{
    // Calculate the midpoint of the array without overflowing
    return start + (end - start) / 2;
}

void print_array(int *arr, int size)
{
    // Loop through the array and print each element, separated by a space
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
