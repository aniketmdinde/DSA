#include <iostream>
using namespace std;

class LinkedList;

class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}

    friend class LinkedList;
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList() : head(NULL), tail(NULL) {}

    // push a node at the front of linked list
    void push_front(int data)
    {
        // Case 1: Linked List Empty i.e. head = NULL and tail = NULL
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail = n;
            return;
        }
        // Case 2: Linked List Not Empty i.e. head != NULL and tail != NULL
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }
};
