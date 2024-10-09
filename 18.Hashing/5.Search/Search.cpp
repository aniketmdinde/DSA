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

    int hash_function(string key)
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

    void rehash()
    {
        // Save ptr to old table
        Node<T> **oldTable = table;

        // Storing table sizes
        int oldTableSize = table_size;
        table_size = 2 * table_size + 1;

        // Create new table
        current_size = 0;
        table = new Node<T> *[table_size];

        // Initialize the new table values as NULL
        for (int i = 0; i < table_size; i++)
            table[i] = NULL;

        // Add elements from old table into new table
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i]; // Points to head of ith linked list

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                insert(key, value);
                temp = temp->next;
            }

            // Destory the ith linked list
            if (oldTable[i] != NULL)
            {
                delete oldTable[i]; // recurively destroys all nodes
            }
        }

        // Destroy the oldTable
        delete[] oldTable;
    }

    void insert(string key, T value)
    {
        // Hashing
        int index = hash_function(key); // 0 to tablesize-1

        // Insert into linked list
        Node<T> *n = new Node<T>(key, value);

        n->next = table[index];
        table[index] = n;

        current_size++;

        // Compute load factor every time and Rehash if exceeds the threshold
        float load_factor = current_size / table_size;

        if (load_factor > 0.7)
            rehash();
    }

    void printHashTable()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << " ";

            Node<T> *temp = table[i];

            while (temp != NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }

    T *search(string key)
    {
        int index = hash_function(key);

        Node<T> *temp = table[index];

        while (temp != NULL)
        {
            if (temp->key == key)
                return &temp->value; // return address of value

            temp = temp->next;
        }

        return NULL; // not present
    }
};

int main()
{
    HashTable<int> h;

    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 240);
    h.insert("Papaya", 280);
    h.insert("Grapes", 320);
    h.insert("Guava", 445);
    h.insert("Strawberry", 90);

    string fruit;
    cin >> fruit;

    int *price = h.search(fruit);
    if (price != NULL)
        cout << "Price of fruit: " << *price << endl;
    else
        cout << "Fruit not found" << endl;

    return 0;
}