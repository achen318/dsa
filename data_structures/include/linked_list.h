#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
    Node *get_node(int index);
    int assert_index(int index);

public:
    // Constructor
    LinkedList();

    // Getters
    int get_size();

    int get(int index);
    int find(int value);

    // Setters
    void set(int index, int value);

    // Mutators
    void add(int value);
    void add(int index, int value);

    int remove(int index);
    int remove_value(int value);

    // Display
    void display();
    void display_info();
};

#endif
