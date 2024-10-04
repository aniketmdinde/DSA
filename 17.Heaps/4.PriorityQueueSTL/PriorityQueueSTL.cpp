#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {10, 15, 20, 13, 6, 90};
    int n = sizeof(arr) / sizeof(int);

    // By default, max heap
    priority_queue<int> heap1;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> heap2; // greater reverse the comparator

    for (int x : arr)
    {
        heap1.push(x);
        heap2.push(x);
    }

    cout << "----- MAX HEAP -----" << endl;
    while (!heap1.empty())
    {
        cout << heap1.top() << " ";
        heap1.pop();
    }
    cout << endl;

    cout << endl;

    cout << "----- MIN HEAP -----" << endl;
    while (!heap2.empty())
    {
        cout << heap2.top() << " ";
        heap2.pop();
    }
    cout << endl;

    return 0;
}
