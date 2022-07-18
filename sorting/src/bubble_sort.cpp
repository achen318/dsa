#include "bubble_sort.h"

#include "helper_functions.h"

void bubble_sort(int *arr, int size)
{
    bool swapped = false;

    while (!swapped)
    {
        // Iterate through array as long as there were swaps
        for (int i = 1; i < size; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                // Remember that a swap is done
                swap(arr, i, i - 1);
                swapped = true;
            }
        }

        // Since the largest element bubbles up, we can reduce the search space by 1
        size--;

        // If swapped is true, then swaps were made, so the array might not be sorted
        // If swapped is false, then no swaps were made, so the array is sorted
        swapped = !swapped;
    }
}
