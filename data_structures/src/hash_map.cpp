#include "hash_map.h"

#include <stdexcept>
#include <string>

// ----- Private methods -----
void HashMap::resize()
{
    // Double the number of buckets
    this->buckets *= 2;

    // Create a new table with the new number of buckets
    EntryNode **new_table = new EntryNode *[this->buckets];

    // Delete the old table
    delete[] this->table;

    // Set the new table to the old table
    this->table = new_table;

    // Fill the new table with null pointers
    for (int i = 0; i < this->buckets; i++)
        this->table[i] = nullptr;

    // Rehash the entries into the new table
    for (int i = 0; i < this->size; i++)
    {
        this->chain_add((this->keys)[i], (this->values)[i]);
    }
}

HashMap::EntryNode *HashMap::get_entry(int key) const
{
    // Get the head of the chain
    EntryNode *entry = this->table[this->hash(key)];

    // Loop through the linked list to find the entry
    while (entry != nullptr)
    {
        if (entry->key == key)
            return entry;

        entry = entry->next;
    }

    // Throw an error if the key is out of range
    throw std::out_of_range("'key' of " + std::to_string(key) + " is not in the hash map");
}

int HashMap::hash(int key) const
{
    return key % this->buckets;
}

void HashMap::chain_add(int key, int value)
{
    // Initialize a new entry node with the given key/value
    EntryNode *entry = new EntryNode(key, value);

    const int index = this->hash(key);

    // Set the next pointer of the new entry to the head of the chain
    EntryNode *head = this->table[index];
    entry->next = head;

    // Set the head of the chain to the new entry
    this->table[index] = entry;
}

void HashMap::chain_remove(int key)
{
    const int index = this->hash(key);

    // Get the head of the chain
    EntryNode *entry = this->table[index];

    if (entry == nullptr)
        return;

    // If the head is the entry to remove, set the head to the next entry
    if (entry->key == key)
    {
        this->table[index] = entry->next;
    }

    // Loop through the chain to find the entry to remove
    else
    {
        while (entry->next != nullptr)
        {
            // If the next entry is the entry to remove
            if ((entry->next)->key == key)
            {
                // The entry to remove's next entry becomes the next entry of the current entry
                entry->next = (entry->next)->next;

                // Set entry to the entry to remove (which is the next entry)
                entry = entry->next;
                break;
            }

            entry = entry->next;
        }
    }

    // Delete the entry
    delete entry;
}

// ----- Constructor -----
HashMap::HashMap()
{
    constexpr int initial_buckets = 16;

    this->table = new EntryNode *[initial_buckets];

    for (int i = 0; i < initial_buckets; i++)
        this->table[i] = nullptr;

    this->size = 0;
    this->buckets = initial_buckets;

    this->keys = ArrayList();
    this->values = ArrayList();
}

// ----- Getters -----
int HashMap::get_size() const
{
    return this->size;
}

ArrayList HashMap::get_keys() const
{
    return this->keys;
}

ArrayList HashMap::get_values() const
{
    return this->values;
}

int HashMap::get(int key) const
{
    return (this->get_entry(key))->value;
}

bool HashMap::has(int key) const
{
    return (this->keys).find(key) != -1;
}

// ----- Setters -----
void HashMap::set(int key, int value)
{
    // Get the entry to set
    EntryNode *entry = this->get_entry(key);

    // Set the value of the entry
    entry->value = value;

    // Update the values array
    const int index = this->keys.find(key);
    this->values[index] = value;
}

// ----- Mutators -----
void HashMap::add(int key, int value)
{
    // Throw an error if the key is already in the hash map
    if (this->has(key))
        throw std::runtime_error("'key' of " + std::to_string(key) + " already exists in the hash map");

    // If the size is 1.5 times the number of buckets, resize the hash map
    if (static_cast<double>(this->size) / this->buckets >= 1.5)
        this->resize();

    // Increment the size
    this->size++;

    // Add the key/value to the keys/values arrays
    this->keys.add(key);
    this->values.add(value);

    // Add the key/value to the table
    this->chain_add(key, value);
}

void HashMap::remove(int key)
{
    // Decrement the size
    this->size--;

    // Delete the key/value from the keys/values arrays
    // The key/value pair have the same indices in the arrays
    const int index = this->keys.remove_value(key);
    this->values.remove(index);

    // Delete the key/value from the table
    this->chain_remove(key);
}

// ----- Display -----
std::ostream &operator<<(std::ostream &out, const HashMap &hash_map)
{
    out << '{';

    int i = 0;

    for (int j = 0; j < hash_map.buckets; j++)
    {
        // Get the head of the chain
        HashMap::EntryNode *entry = hash_map.table[j];

        // Loop through the linked list to display the entries
        while (entry != nullptr)
        {
            out << entry->key << ": " << entry->value;
            entry = entry->next;

            // If this is not the last entry, add a separator
            if (i != hash_map.size - 1)
                out << ", ";

            // Increment the number of entries printed
            i++;
        }
    }

    out << '}';

    return out;
}

void HashMap::display_info() const
{
    std::cout << "HashMap  - " << *this << '\n';
    std::cout << "Keys     - " << this->keys << '\n';
    std::cout << "Values   - " << this->values << '\n';
    std::cout << "Size     - " << this->size << '\n';
    std::cout << "Buckets  - " << this->buckets << "\n\n";
}
