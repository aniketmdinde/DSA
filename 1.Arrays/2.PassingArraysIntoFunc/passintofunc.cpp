#include <iostream>
using namespace std;

void printArray(int arr[], int n) // accepts array and number of elements
{
    // cout << "In function " << sizeof(arr) << endl;
    arr[0] = 100;
    cout << "In function " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int); // computing num of elements

    printArray(arr, n);

    cout << "In main " << sizeof(arr) << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
