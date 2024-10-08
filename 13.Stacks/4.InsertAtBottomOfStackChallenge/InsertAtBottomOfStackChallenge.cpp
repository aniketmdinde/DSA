#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int data)
{
    // Base case
    if (s.empty())
    {
        s.push(data);
        return;
    }

    // Recursive case
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    insertAtBottom(s, 5);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}