#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    cout << arr << endl;

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;

    // Freeing up memory
    delete[] arr;

    // Even after freeing up memory, we are able to access the address of the arr
    //  But since the dynamic memory is freed we cannot access its content since freed and we get garbage value
    cout << arr << endl;
    cout << *arr << endl;

    return 0;
}