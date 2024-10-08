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

    ~Node()
    {
        if (next != NULL)
            delete next; // recursively destroys entire linked list
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

    void hash_function(string key)
    {
        int index = 0;
        int power = 1;

        for (char ch : key)
        {
            index = (index + ch * power) % table_size; // (a*29^0) % tablesize + (a*29^0) % tablesize + ...
            power = (power * 29) % table_size;         // To avoid overflow
        }

        return index;
    }

    void insert(string key, T value)
    {
        // Hashing
        int index = hash_function(key); // 0 to tablesize-1

        // Insert into linked list
        Node<t> *n = new Node<T>(key, value);

        n->next = table[index];
        table[index] = n;

        current_size++;
    }
};
