#include <iostream>
using namespace std;

template <typename T>
class Stack;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T d)
    {
        this->data = d;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    bool empty()
    {
        return (head == NULL);
    }

    T top()
    {
        return head->data;
    }

    void pop()
    {
        if (!empty())
        {
            Node<T> *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main()
{
    Stack<char> s;
    s.push('g');
    s.push('n');
    s.push('i');
    s.push('k');

    // Printting
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop(); // to bring next char to top
    }

    return 0;
}