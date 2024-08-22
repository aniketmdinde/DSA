#include <iostream>
#include <vector> //include for using vectors
using namespace std;

int main()
{
    vector<int> arr; // Decalration
    cout << arr.size() << endl;

    arr = {1, 2, 3, 4, 5}; // Initialization
    cout << arr.size() << endl;

    // Capacity of vector
    cout << arr.capacity() << endl;

    // push_back - insert element at end of array
    arr.push_back(10);
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    // Print elements
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    // pop_back - remove last element
    arr.pop_back();

    for (int a : arr)
        cout << a << " ";
    cout << endl;

    // Using fill constructors
    vector<int> x(10, 7); // 10 elements each with value 7

    for (int a : x)
        cout << a << " ";
    cout << endl;

    return 0;
}