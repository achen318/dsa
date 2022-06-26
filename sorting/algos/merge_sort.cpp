#include "merge_sort.h"

#include "helper_functions.h"

#include <algorithm>
#include <iostream>

void merge(int *arr, int start, int mid, int end)
{
    // Make temporary copies of the lower and upper halves
    const int lower_size = mid - start;
    const int upper_size = end - mid;

    int lower_half_arr[lower_size];
    std::copy(arr + start, arr + mid, lower_half_arr);

    int upper_half_arr[upper_size];
    std::copy(arr + mid, arr + end, upper_half_arr);

    // Repeatedly copy the lower element of the two halves into the original array
    int lower_i = 0;
    int upper_i = 0;

    for (int arr_i = start; arr_i < end; arr_i++)
    {
        const int lower_elem = lower_half_arr[lower_i];
        const int upper_elem = upper_half_arr[upper_i];

        // If lower_i is in range and either upper_i is out of range or lower_elem <= upper_elem
        if (lower_i < lower_size && (upper_i >= upper_size || lower_elem <= upper_elem))
        {
            // Copy the lowest elem from the lower arr, and increment the lower index
            arr[arr_i] = lower_elem;
            lower_i++;
        }

        // If lower_i is out of range or both upper_i is in range and lower_elem > upper_elem
        else
        {
            // Copy the lowest elem from the upper arr, and increment the upper index
            arr[arr_i] = upper_elem;
            upper_i++;
        }
    }
}

void divide(int *arr, int start, int end)
{
    // ----- base case -----
    if (end - start <= 1)
        // The subarray has a size of 0 or 1, so it cannot be divided/sorted further
        return;

    // ----- recursive case -----
    else
    {
        const int mid = (start + end) / 2;

        // Recursively divide array into 2
        divide(arr, start, mid); // lower half: [start, mid)
        divide(arr, mid, end);   // upper half: [mid, end)

        // Merge & sort the 2 halves of the array
        merge(arr, start, mid, end);
    }
}

void merge_sort(int *arr, int size)
{
    divide(arr, 0, size);
}
