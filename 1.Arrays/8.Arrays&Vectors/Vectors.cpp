#include <iostream>
#include <vector> //include this library to use vectors
using namespace std;

int main()
{
    // // vector<int> v;            // vector declaration
    // // cout << v.size() << endl; // size() method returns the size of vector

    // vector<int> v = {1, 2, 3, 4, 5}; // initialization
    // cout << v.size() << endl;        // size tells the number of elements
    // cout << v.capacity() << endl;    // capacity tells the actual allocated memory to the vector

    // // Push_back => enter the element at the end in constant time
    // v.push_back(6);
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;

    // // Print all elements
    // cout << "Elements of vector: " << endl;
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << endl;

    // // Pop_back => removes the last element
    // v.pop_back();

    // cout << "Elements of vector: " << endl;
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << endl;

    // Using fill constructor
    vector<int> v(10, 7); // 10 elements each with value 7
    cout << "Elements of vector: " << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}