#include "array_list.h"

#include <iostream>
#include <stdexcept>
#include <string>

// ----- Private methods -----
void ArrayList::resize()
{
    // Double the capacity
    this->capacity *= 2;

    // Create a new array with the new capacity
    int *new_array = new int[this->capacity];

    // Copy the old array into the new array
    for (int i = 0; i < this->size; i++)
        new_array[i] = this->get(i);

    // Delete the old array
    delete[] this->array;

    // Set the new array to the old array
    this->array = new_array;
}

int ArrayList::assert_index(int index)
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("'index' of " + std::to_string(index) + " is out of range");

    return index;
}

// ----- Constructor -----
ArrayList::ArrayList()
{
    this->size = 0;
    this->capacity = 1;
    this->array = new int[1];
}

// ----- Getters -----
int ArrayList::get_size()
{
    return this->size;
}

int ArrayList::get(int index)
{
    return this->array[assert_index(index)];
}

bool ArrayList::has(int value)
{
    for (int i = 0; i < this->size; i++)
        if (this->get(i) == value)
            return true;

    return false;
}

// ----- Setters -----
void ArrayList::set(int index, int value)
{
    this->array[assert_index(index)] = value;
}

// ----- Mutators -----
void ArrayList::add(int value)
{
    this->add(this->size, value);
}

void ArrayList::add(int index, int value)
{
    // If the array is full, resize it
    if (this->size == this->capacity)
        this->resize();

    // Increment the size
    this->size++;

    // Shift all elements after the index to the right
    for (int i = this->size - 1; i > index; i--)
        this->set(i, this->get(i - 1));

    // Set the value at the index
    this->set(index, value);
}

int ArrayList::remove(int index)
{
    // Save the value at the index
    const int removed = this->get(index);

    // Shift all elements after the index to the left
    for (int i = index; i < this->size - 1; i++)
        this->set(i, this->get(i + 1));

    // Decrement the size
    this->size--;

    // Return the removed value
    return removed;
}

// ----- Display -----
void ArrayList::display()
{
    std::cout << '[';

    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->get(i);

        // If this is not the last element, add a separator
        if (i != this->size - 1)
            std::cout << ", ";
    }

    std::cout << "]\n";
}

void ArrayList::display_info()
{
    std::cout << "ArrayList - ";
    this->display();
    std::cout << "Size      - " << this->size << '\n';
    std::cout << "Capacity  - " << this->capacity << "\n\n";
}
