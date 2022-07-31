#include "linked_list.h"

#include <stdexcept>
#include <string>

// ----- Private methods -----
LinkedList::Node *LinkedList::get_node(int index) const
{
    Node *node = this->head;

    for (int i = 0; i < assert_index(index); i++)
        node = node->next;

    return node;
}

int LinkedList::assert_index(int index) const
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("'index' of " + std::to_string(index) + " is out of range");

    return index;
}

// ----- Constructor -----
LinkedList::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

// ----- Subscription -----
int &LinkedList::operator[](int index)
{
    return this->get_node(index)->value;
}

int LinkedList::operator[](int index) const
{
    return this->get_node(index)->value;
}

// ----- Getters -----
int LinkedList::get_size() const
{
    return this->size;
}

int LinkedList::find(int value) const
{
    for (int i = 0; i < this->size; i++)
        if ((*this)[i] == value)
            return i;

    return -1;
}

// ----- Mutators -----
void LinkedList::add(int value)
{
    this->add(this->size, value);
}

void LinkedList::add(int index, int value)
{
    // Increment the size
    this->size++;

    // Initialize a new node with the given value
    Node *new_node = new Node(value);

    if (index == 0)
    {
        // The current head becomes the new node's next
        new_node->next = this->head;

        // The new node becomes the head
        this->head = new_node;
    }
    else
    {
        Node *previous_node = this->get_node(index - 1);

        // The next node is the node at the given index (previous node's next)
        new_node->next = previous_node->next;

        // The new node becomes the next node of the previous node
        previous_node->next = new_node;
    }
}

int LinkedList::remove(int index)
{
    Node *current_node;

    if (index == 0)
    {
        // The head is the node at index 0, which will be removed
        current_node = this->head;

        // The next node becomes the head
        this->head = current_node->next;
    }
    else
    {
        // Done to avoid using get_node() twice
        Node *previous_node = this->get_node(index - 1);
        current_node = previous_node->next;

        // The next node becomes the next node of the previous node
        previous_node->next = current_node->next;
    }

    // Save the value of the removed node & delete the node
    const int removed = current_node->value;
    delete current_node;

    // Decrement the size
    this->size--;

    // Return the value of the removed node
    return removed;
}

int LinkedList::remove_value(int value)
{
    // Find the index of the first occurrence of the value
    const int index = this->find(value);

    // Remove the value at the index
    if (index != -1)
        this->remove(index);

    return index;
}

// ----- Display -----
std::ostream &operator<<(std::ostream &out, const LinkedList &linked_list)
{
    out << '[';

    for (int i = 0; i < linked_list.size; i++)
    {
        out << linked_list[i];

        if (i < linked_list.size - 1)
            out << " -> ";
    }

    out << ']';

    return out;
}

void LinkedList::display_info() const
{
    std::cout << "LinkedList - " << *this << '\n';
    std::cout << "Size       - " << this->size << "\n\n";
}
