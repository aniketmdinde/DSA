#include <iostream>
using namespace std;

bool isSorted1(int arr[], int n)
{
    // base case
    if (n == 1 or n == 0)
        return true;

    // recursive case
    if (arr[0] < arr[1] and isSorted1(arr + 1, n - 1))
        return true;

    return false; // if recursive condition fails
}

bool isSorted2(int arr[], int n, int i)
{
    // base case
    if (i == n - 1)
        return true;

    // recursive case
    if (arr[i] < arr[i + 1] and isSorted2(arr, n, i + 1))
        return true;

    return false; // if recursive condition fails
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}; // sorted
    // int arr[] = {1, 2, 3, 4, 6, 5}; // unsorted

    int n = sizeof(arr) / sizeof(int);

    if (isSorted1(arr, n))
        cout << "Array is Sorted" << endl;
    else
        cout << "Array is NOT Sorted" << endl;

    return 0;
}
