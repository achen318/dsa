#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "array_list.h"

class HashMap
{
private:
    class EntryNode
    {
    public:
        int key;
        int value;
        EntryNode *next;

        EntryNode(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };

    EntryNode **table;

    int size;
    int buckets;

    ArrayList keys;
    ArrayList values;

    // Private methods
    void resize();

    EntryNode *get_entry(int key);

    int hash(int key);

    void chain_add(int key, int value);
    void chain_remove(int key);

public:
    // Constructor
    HashMap();

    // Getters
    int get_size();
    ArrayList get_keys();
    ArrayList get_values();

    int get(int key);
    bool has(int key);

    // Setters
    void set(int key, int value);

    // Mutators
    void add(int key, int value);
    void remove(int key);

    // Display
    void display(int padding_len);
    void display_info();
};

#endif
