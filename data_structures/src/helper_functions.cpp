#include "helper_functions.h"

#include <stdexcept>

int assert_index(int index, int size)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("'index' of " + std::to_string(index) + " is out of range");

    return index;
}
