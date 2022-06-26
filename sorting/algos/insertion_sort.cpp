#include "insertion_sort.h"

#include "helper_functions.h"

void insert(int *arr, int size, int index)
{
    while (index > 0 && arr[index - 1] > arr[index])
    {
        // Swap element if current element is smaller
        swap(arr, index, index - 1);
        index--;
    }
}

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        // Insert the current element at its correct position
        insert(arr, size, i);
    }
}
