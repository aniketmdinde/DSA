#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *n = new Node(data);
    n->next = head;
    head = n;
}

bool containsCycle(Node *head)
{
    unordered_map<Node *, bool> hashtable;

    Node *temp = head;

    while (temp != NULL)
    {
        // Check if temp already exist i.e cycle present
        if (hashtable.count(temp) != 0)
            return true;

        // Make a new entry true
        hashtable[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *a = NULL;
    insertAtHead(a, 1);
    insertAtHead(a, 2);
    insertAtHead(a, 3);
    insertAtHead(a, 3);
    insertAtHead(a, 3);

    // Cycle
    // Node *temp = a->next->next->next->next;
    // temp->next = a->next->next;

    if (containsCycle(a))
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }

    return 0;
}