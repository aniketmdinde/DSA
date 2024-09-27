#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    bool empty()
    {
        return q1.empty() and q2.empty();
    }

    void push(int data)
    {
        if (!q1.empty())
        {
            q1.push(data);
        }
        else
        {
            q2.push(data);
        }
    }

    void pop()
    {
        if (empty())
        {
            return;
        }

        if (q1.empty())
        {
            // Shift element from q2 to q1
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();

                if (q2.empty())
                    break;

                q1.push(front);
            }
        }
        else
        {
            // Shift element from q1 to q2
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();

                if (q1.empty())
                    break;

                q2.push(front);
            }
        }
    }

    int top()
    {
        if (q1.empty())
        {
            // Shift element from q2 to q1
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();
                q1.push(front);

                if (q2.empty())
                    return front;
            }
        }
        else
        {
            // Shift element from q1 to q2
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();
                q2.push(front);

                if (q1.empty())
                    return front;
            }
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}