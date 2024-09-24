#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int d) : data(d), next(NULL) {} // Initialization list
};

class LinkedList
{
    Node *head;
    Node *tail; // for inserting at tail (optional)

public:
    LinkedList() : head(NULL), tail(NULL) {}
};
