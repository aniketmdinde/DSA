#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int current_size;
    int maximum_size;
    int front;
    int rear;

public:
    Queue(int default_size = 5)
    {
        maximum_size = default_size;
        arr = new int[maximum_size];

        current_size = 0;
        front = 0;
        rear = maximum_size - 1;
    }

    bool full()
    {
        return (current_size == maximum_size);
    }

    bool empty()
    {
        return (current_size == 0);
    }

    void push(int data)
    {
        if (!full())
        {
            // Move rear to next index
            rear = (rear + 1) % maximum_size;
            arr[rear] = data;
            current_size++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % maximum_size;
            current_size--;
        }
    }

    int getFront()
    {
        return arr[front];
    }
};

int main()
{
    Queue q(7);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8); // overflow
    q.pop();

    while (!q.empty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
    cout << endl;
}
