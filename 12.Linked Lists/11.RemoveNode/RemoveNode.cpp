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

    // Destructore - delete Node
    ~Node()
    {
        if (next != NULL)
            delete next; // recursive call to next node
    }
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
        if (start == NULL)
            return -1;

        // Recursive case
        if (start->data == key)
            return 0;

        int subIndex = searchHelper(start->next, key);

        if (subIndex == -1)
            return -1;

        return subIndex + 1;
    }

    int recursiveSearch(int key)
    {
        int index = searchHelper(head, key);
        return index;
    }

    // Destructor - to delete linked list
    ~LinkedList()
    {
        if (head != NULL)
            delete head;

        head = NULL;
    }

    // Removing a node from head of Linked List
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // Removing a node from end of Linked List
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL) // second last node
            temp = temp->next;

        tail = temp; // Changing tail ptr

        delete temp->next;

        temp->next = NULL;
    }

    // Removing node at a particular position
    void removeNode(int position)
    {
        if (position == 0)
        {
            pop_front();
            return;
        }

        Node *temp = head;
        for (int jump = 1; jump <= position - 1; jump++)
            temp = temp->next;

        if (temp == tail)
        {
            pop_back();
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;
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

    l.removeNode(2); // middle node

    // Print LL
    head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    l.removeNode(0); // first node

    // Print LL
    head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    l.removeNode(1); // last node

    // Print LL
    head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}
