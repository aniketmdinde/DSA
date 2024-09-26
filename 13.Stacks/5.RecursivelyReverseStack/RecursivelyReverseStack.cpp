#include <iostream>
#include <stack>
using namespace std;

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

void reverse(stack<int> s)
{
    // Base case
    if (s.empty())
        return;

    // Recursive case
    int data = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, data);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}