#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class LinkedList
{
private:
    class Node
    {
    public:
        int value;
        Node *next;

        Node(int value)
        {
            this->value = value;
            this->next = nullptr;
        }
    };

    Node *head;
    int size;

    // Private methods
    Node *get_node(int index) const;
    int assert_index(int index) const;

public:
    // Constructor
    LinkedList();

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
    friend std::ostream &operator<<(std::ostream &out, const LinkedList &linked_list);
    void display_info() const;
};

#endif
