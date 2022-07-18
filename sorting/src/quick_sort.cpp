#include "quick_sort.h"

#include "helper_functions.h"

int partition(int *arr, int start, int end)
{
    // Choose the middle element as the pivot
    const int pivot_val = arr[mid_point(start, end)];

    // Initiate left and right pointers to be offset by 1
    int left_i = start - 1;
    int right_i = end;

    // Move pointers until they meet, swapping elements as necessary
    while (true)
    {
        // Move left pointer right until the value is >= the pivot
        do
        {
            left_i++;
        } while (arr[left_i] < pivot_val);

        // Move right pointer left until the value is <= the pivot
        do
        {
            right_i--;
        } while (arr[right_i] > pivot_val);

        // The elements are partitioned into 2 parts less than and greater than pivot
        // Return the index of the pivot if the pointers meet
        if (left_i >= right_i)
            return left_i;

        // Swap the values because there is an inversion
        swap(arr, left_i, right_i);
    }
}

void quick_sort(int *arr, int start, int end)
{
    // ----- base case -----
    if (end - start <= 1)
        // The subarray has a size of 0 or 1, so it cannot be sorted further
        return;

    // ----- recursive case -----
    else
    {
        // Partition the array and get the index of the pivot
        const int pivot = partition(arr, start, end);

        // Recursively sort the subarrays
        quick_sort(arr, start, pivot); // left subarray : [start, pivot)
        quick_sort(arr, pivot, end);   // right subarray: [pivot, end)
    }
}

void quick_sort(int *arr, int size)
{
    quick_sort(arr, 0, size);
}
