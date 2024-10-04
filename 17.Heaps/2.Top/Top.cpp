#include <iostream>
#include <vector> // for using dynamic array
using namespace std;

class Heap
{
    vector<int> v;

public:
    Heap(int default_size = 10)
    {
        v.reserve(default_size); // creates memory for 10 integers
        v.push_back(-1);         // block 0th index

        // index of last elemnt can be found using v.size()-1
        // So we need to insert every new element at v.size() which us handled by vector automatically
    }

    void push(int data)
    {
        // add data at end of heap
        v.push_back(data);

        // Following MIN heap property
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 and v[index] < v[parent])
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    void printHeap()
    {
        for (int i = 1; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }

    int top()
    {
        return v[1];
    }
};

int main()
{
    Heap h;
    h.push(10);
    h.push(20);
    h.push(40);
    h.push(30);
    h.push(3);

    h.printHeap();

    cout << h.top() << endl;

    return 0;
}
