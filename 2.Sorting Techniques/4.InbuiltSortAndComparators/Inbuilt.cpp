#include <iostream>
#include <algorithm> //include for working with inbuilt sort function
using namespace std;

bool compare(int a, int b)
{
    // return a > b; // makes the array descending
    return a < b; // makes the array ascending
}

int main()
{
    int arr[] = {10, 9, 8, 6, 5, 4, 3, 2, 11, 16, 8};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr + n);    // takes start and end of the array - end is non inclusive
    reverse(arr, arr + n); // for reversing - also takes start and end of the array

    // sort(arr, arr + n, compare); // using comparator

    sort(arr, arr + n, greater<int>()); // using inbuilt comparator
    sort(arr, arr + n, less<int>());    // using inbuilt comparator

    for (int a : arr)
        cout << a << endl;

    return 0;
}