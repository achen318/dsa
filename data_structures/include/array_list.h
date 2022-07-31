#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>

class ArrayList
{
private:
    int *array;
    int size;
    int capacity;

    // Private methods
    void resize();
    int assert_index(int index) const;

public:
    // Constructor
    ArrayList();

    // Getters
    int get_size() const;

    int get(int index) const;
    int find(int value) const;

    // Setters
    void set(int index, int value);

    // Mutators
    void add(int value);
    void add(int index, int value);

    int remove(int index);
    int remove_value(int value);

    // Display
    friend std::ostream &operator<<(std::ostream &out, const ArrayList &array_list);
    void display_info() const;
};

#endif
