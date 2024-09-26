#include <iostream>
using namespace std;

template <typename T>
class Queue;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T d)
    {
        this->data = d;
        this->next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void push(T data) // insertion at back
    {
        Node<T> *temp = new Node<T>(data);

        if (tail == NULL)
        {
            tail = temp;
            head = tail;
            return;
        }

        tail->next = temp;
        tail = temp;
    }

    void pop() // deletion from front
    {
        Node<T> *temp;

        if (head == NULL)
        {
            return;
        }

        temp = head;
        head = head->next;
        temp->next = NULL;

        if (head != NULL and head == tail)
        {
            tail = NULL;
            return;
        }

        delete temp;
    }

    T top()
    {
        return head->data;
    }

    void printQueue()
    {
        Node<T> *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.printQueue();

    q.pop();

    q.printQueue();

    return 0;
}