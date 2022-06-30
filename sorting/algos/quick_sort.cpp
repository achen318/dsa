#include "quick_sort.h"

#include "helper_functions.h"

int partition(int *arr, int start, int end)
{
    // Choose the middle element as the pivot
    const int pivot = arr[(start + end) / 2];

    // Initiate left and right pointers
    int left_i = start;
    int right_i = end - 1;

    // Move pointers until they meet, swapping elements as necessary
    while (left_i < right_i)
    {
        // Move left pointer right until it finds a value greater than pivot
        while (arr[left_i] < pivot)
            left_i++;

        // Move right pointer left until it finds a value less than pivot
        while (arr[right_i] > pivot)
            right_i--;

        // Swap the values because there is an inversion
        swap(arr, left_i, right_i);
    }

    // The elements are partitioned into 2 parts less than and greater than pivot
    // Return the index of where the pivot is
    return left_i;
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

        // Recursively sort the subarrays, left and right of the pivot
        quick_sort(arr, start, pivot);   // left subarray : [start, pivot)
        quick_sort(arr, pivot + 1, end); // right subarray: [pivot + 1, end)
    }
}

void quick_sort(int *arr, int size)
{
    quick_sort(arr, 0, size);
}
