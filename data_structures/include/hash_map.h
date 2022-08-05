#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "array_list.h"

#include <iostream>

class HashMap
{
private:
    struct EntryNode
    {
        int key;
        int value;
        EntryNode *next;

        EntryNode(int key, int value) : key(key), value(value), next(nullptr) {}
    };

    EntryNode **table;

    int size;
    int buckets;

    ArrayList keys;
    ArrayList values;

    // Private methods
    void resize();

    EntryNode *get_entry(int key) const;

    int hash(int key) const;

    void chain_add(int key, int value);
    void chain_remove(int key);

public:
    // Constructor
    HashMap();

    // Getters
    int get_size() const;
    ArrayList get_keys() const;
    ArrayList get_values() const;

    int get(int key) const;
    bool has(int key) const;

    // Setters
    void set(int key, int value);

    // Mutators
    void add(int key, int value);
    void remove(int key);

    // Display
    friend std::ostream &operator<<(std::ostream &out, const HashMap &hash_map);
    void display_info() const;
};

#endif
