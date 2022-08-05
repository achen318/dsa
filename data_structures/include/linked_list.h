#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;

        Node(int value) : value(value), next(nullptr) {}
    };

    Node *head;
    int size;

    // Private methods
    Node *get_node(int index) const;
    int assert_index(int index) const;

public:
    // Constructor
    LinkedList();

    // Subscription
    int &operator[](int index);
    int operator[](int index) const;

    // Getters
    int get_size() const;
    int find(int value) const;

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
