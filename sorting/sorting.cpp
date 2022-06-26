#include "insertion_sort.h"
#include "selection_sort.h"

#include "helper_functions.h"

#include <algorithm>
#include <iostream>

constexpr char seperator[] = "----------";

void test_sorting_algo(std::string name, void (*func)(int *, int), int *arr, int *sorted_arr, int size)
{
    // Deep copy the array
    int new_arr[size];
    std::copy(arr, arr + size, new_arr);

    // Apply sorting algorithm
    func(new_arr, size);

    // Determine if the sorting is successful
    const char success_state = (std::equal(new_arr, new_arr + size, sorted_arr)) ? 'Y' : 'N';

    // Display info on the sorting algorithm (name & success state)
    std::cout << seperator << ' ' << name << " [" << success_state << "] " << seperator << '\n';

    // Print the pre-sorted array
    std::cout << "Before: ";
    print_array(arr, size);

    // Print the post-sorted array
    std::cout << "After : ";
    print_array(new_arr, size);
}

int main()
{
    int arr[]{5, 2, 4, 6, 1};
    int sorted_arr[]{1, 2, 4, 5, 6};

    test_sorting_algo("Insertion Sort", insertion_sort, arr, sorted_arr, 5);
    test_sorting_algo("Selection Sort", selection_sort, arr, sorted_arr, 5);

    return 0;
}
