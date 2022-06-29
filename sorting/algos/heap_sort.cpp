#include "heap_sort.h"

#include "helper_functions.h"

void heapify(int *arr, int parent_i, int size)
{
    int max_i = parent_i;

    // Indices of the left and right child nodes given the index of the parent node
    const int left_i = 2 * parent_i + 1;
    const int right_i = 2 * parent_i + 2;

    // Update max_i if the child node is greater than the parent node
    if (left_i < size && arr[left_i] > arr[max_i])
        max_i = left_i;
    if (right_i < size && arr[right_i] > arr[max_i])
        max_i = right_i;

    // If the parent node is not the max node, swap them & recursively heapify the subtree
    if (max_i != parent_i)
    {
        swap(arr, max_i, parent_i);
        heapify(arr, max_i, size);
    }
}

void heap_sort(int *arr, int size)
{
    // Build a max heap by heapifying each parent node
    int i = size / 2; // index of last parent node

    while (i --> 0)
        heapify(arr, i, size);

    // The array consists of a max heap and a sorted array
    // Decrement max heap size until the heap is empty
    while (size --> 0)
    {
        // Swap the root node (max elem) with the last node
        // This puts the max elem at the start of the sorted array
        swap(arr, 0, size);

        // Update the heap to maintain the heap property
        heapify(arr, 0, size);
    }
}
