#include <iostream>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b; // MIN HEAP
        // return a < b; // MAX HEAP
    }
};

int main()
{
    int arr[] = {10, 15, 20, 13, 6, 90};
    int n = sizeof(arr) / sizeof(int);

    priority_queue<int, vector<int>, Compare> heap; // using custom comparator

    for (int x : arr)
    {
        heap.push(x);
    }

    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    return 0;
}
