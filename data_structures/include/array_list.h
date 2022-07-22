#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

class ArrayList
{
private:
    int *array;
    int size;
    int capacity;

    // Private methods
    void resize();
    int assert_index(int index);

public:
    // Constructors
    ArrayList();
    ArrayList(int capacity);

    // Getters
    int get_size();

    int get(int index);
    bool has(int value);

    // Setters
    void set(int index, int value);

    // Mutators
    void add(int value);
    void add(int index, int value);

    int remove(int index);

    // Display
    void display();
    void display_info();
};

#endif
