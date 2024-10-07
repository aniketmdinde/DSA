#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

template <typename T>
class HashTable
{
    Node<T> **table;
    int current_size; // total entries inserted including linked list nodes
    int table_size;   // size of table

public:
    HashTable(int default_size = 7)
    {
        table_size = default_size;
        current_size = 0;
        table = new Node<T> *[table_size]; // node* type

        // Clearing garbage from each entry in table
        for (int i = 0; i < table_size; i++)
            table[i] = NULL;
    }
};
