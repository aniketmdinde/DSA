#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key) // check if current element matches with the key
            return i;      // return index
    }

    return -1;
}

int main()
{
    int arr[] = {10, 15, 20, 30, 35, 9, 6, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cin >> key;

    int index = linear_search(arr, n, key);

    if (index != -1)
        cout << key << " is present at index " << index << endl;
    else
        cout << key << " is not found" << endl;

    return 0;
}