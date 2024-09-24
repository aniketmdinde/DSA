#include <iostream>
using namespace std;

class LinkedList; // Forward Declaration

class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {} // Initialization list

    friend class LinkedList; // This gives LinkedList class access to private variables
};

class LinkedList
{
    Node *head;
    Node *tail; // for inserting at tail (optional)

public:
    LinkedList() : head(NULL), tail(NULL) {}
};
