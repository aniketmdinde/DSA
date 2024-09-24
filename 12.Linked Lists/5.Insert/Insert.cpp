#include <iostream>
using namespace std;

class LinkedList;

class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}

    // return data
    int getData()
    {
        return data;
    }

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
            this->head = this->tail = n;
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

    // push a node at the end of linked list
    void push_back(int data)
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
            tail->next = n;
            tail = n;
        }
    }

    // returns the head
    Node *begin()
    {
        return head;
    }

    // Insert an element
    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            push_front(data);
            return;
        }

        // Otherwise
        Node *temp = head;
        for (int jump = 1; jump <= pos - 1; jump++)
            temp = temp->next;

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
};

int main()
{
    LinkedList l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);

    l.insert(2, 2);
    l.insert(10, 0);

    // Print LL
    Node *head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
