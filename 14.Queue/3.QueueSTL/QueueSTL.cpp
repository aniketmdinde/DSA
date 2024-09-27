#include <iostream>
#include <queue> //STL library for queue
using namespace std;

int main()
{
    queue<int> q; // Declaring a queue

    // Push Operation
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
