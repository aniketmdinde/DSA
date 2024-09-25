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

    int LinearSearch(int key)
    {
        int index = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == key)
                return index;

            index++;
            temp = temp->next;
        }

        return -1;
    }

    // Helper function
    int searchHelper(Node *start, int key)
    {
        // base case
        if (start == NULL) // end of linked list
            return -1;

        // if element found
        if (start->data == key)
            return 0;

        // if element not found, recursively call on remaining linked list
        int subIndex = searchHelper(start->next, key);

        // if subindex is -1, return -1
        // else return subIndex + 1 i.e. element found
        if (subIndex == -1)
            return -1;

        return subIndex + 1;
    }

    // Searches for an element in Linked List recursively
    int recursiveSearch(int key)
    {
        int index = searchHelper(head, key);
        return index;
    }
};

int main()
{
    LinkedList l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);

    // Print LL
    Node *head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    cout << l.recursiveSearch(0) << endl;
    cout << l.recursiveSearch(1) << endl;
    cout << l.recursiveSearch(2) << endl;
    cout << l.recursiveSearch(3) << endl;
    cout << l.recursiveSearch(4) << endl;
    cout << l.recursiveSearch(10) << endl;

    return 0;
}
