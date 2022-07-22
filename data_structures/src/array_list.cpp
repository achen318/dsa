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
        new_array[i] = this->array[i];

    // Delete the old array
    delete[] this->array;

    // Set the new array to the old array
    this->array = new_array;
}

int ArrayList::assert_index(int index)
{
    const int size = this->size;

    if (index < 0 || index >= size)
        throw std::out_of_range("'index' of " + std::to_string(index) + " is out of range");

    return index;
}

// ----- Constructors -----
ArrayList::ArrayList() : ArrayList(1) {}

ArrayList::ArrayList(int capacity)
{
    if (capacity < 1)
        throw std::invalid_argument("'capacity' of " + std::to_string(capacity) + "must be greater than 0");

    this->size = 0;
    this->capacity = capacity;
    this->array = new int[capacity];
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
        if (this->array[i] == value)
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

    // Shift all elements after the index to the right
    for (int i = this->size; i > index; i--)
        this->array[i] = this->array[i - 1];

    // Increment the size
    this->size++;

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
        std::cout << this->array[i];

        // If this is not the last element, add a separator
        if (i != this->size - 1)
            std::cout << ", ";
    }

    std::cout << "]\n";
}

void ArrayList::display_info()
{
    std::cout << "Array    - ";
    this->display();
    std::cout << "Size     - " << this->size << '\n';
    std::cout << "Capacity - " << this->capacity << "\n\n";
}