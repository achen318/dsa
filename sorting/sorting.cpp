#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

#include "helper_functions.h"

#include <algorithm>
#include <iostream>
#include <time.h>

constexpr char seperator[] = "----------";

void test_algo(std::string name, void (*func)(int *, int), int *arr, int *sorted_arr, int size)
{
    // Deep copy the array
    int new_arr[size];
    std::copy(arr, arr + size, new_arr);

    // Apply sorting algorithm
    func(new_arr, size);

    // Determine if the sorting is successful
    const bool is_sorted = std::equal(new_arr, new_arr + size, sorted_arr);

    // Display info on the sorting algorithm (name & if the sorting is successful)
    std::cout << name << " - " << (is_sorted ? "SUCCESS" : "FAIL") << '\n';
    if (!is_sorted)
    {
        // Display the array if it is incorrectly sorted
        std::cout << "  -> ";
        print_array(new_arr, size);
    }
}

// Test the sorting algorithms on a given array
void test_algos(int *arr, int size)
{
    // Deep copy the array
    int sorted_arr[size];
    std::copy(arr, arr + size, sorted_arr);

    // Sort the array using std::sort from the C++ STL
    std::sort(sorted_arr, sorted_arr + size);

    // Print separator
    std::cout << seperator << " [" << size << "] " << seperator << '\n';

    // Print the pre-sorted array
    std::cout << "Before: ";
    print_array(arr, size);

    // Print the post-sorted array
    std::cout << "After : ";
    print_array(sorted_arr, size);
    std::cout << '\n';

    // Test std::sort results against the other sorting algorithms
    test_algo("Bubble Sort   ", bubble_sort, arr, sorted_arr, size);
    test_algo("Heap Sort     ", heap_sort, arr, sorted_arr, size);
    test_algo("Insertion Sort", insertion_sort, arr, sorted_arr, size);
    test_algo("Merge Sort    ", merge_sort, arr, sorted_arr, size);
    test_algo("Quick Sort    ", quick_sort, arr, sorted_arr, size);
    test_algo("Selection Sort", selection_sort, arr, sorted_arr, size);
}

// Test the sorting algorithms on a random array of a given size
void test_algos(int size)
{
    // Initialize an array with given size
    int arr[size];

    // Generate a random array of integers in the range [0, 100)
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    // Test the sorting algorithms on this random array
    test_algos(arr, size);
}

int main()
{
    // Initialize a random seed
    srand(time(NULL));

    // Test the sorting algorithms on random arrays of different sizes
    test_algos(0);
    test_algos(1);
    test_algos(2);

    test_algos(5);
    test_algos(10);

    test_algos(100);

    return 0;
}
