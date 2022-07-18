#include "selection_sort.h"

#include "helper_functions.h"

int get_min_index(int *arr, int start, int end)
{
    // Get the index of the smallest element in [start, end)
    int min_index = start;

    for (int i = start + 1; i < end; i++)
    {
        // Update with new min index if current element is smaller
        if (arr[i] < arr[min_index])
            min_index = i;
    }

    return min_index;
}

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        // Swap the current element with the min element
        swap(arr, i, get_min_index(arr, i, size));
    }
}
