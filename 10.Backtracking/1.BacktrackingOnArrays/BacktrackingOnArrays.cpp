#include <iostream>
using namespace std;

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void FillArray(int *arr, int n, int i, int val)
{
    // Base case
    if (i == n)
    {
        // print array
        PrintArray(arr, n);

        return;
    }

    // Recursive case
    arr[i] = val;
    FillArray(arr, n, i + 1, val + 1);

    // Backtracking step
    arr[i] = -1 * arr[i];
}

int main()
{
    int arr[100] = {0};

    int n;
    cin >> n;

    FillArray(arr, n, 0, 1);
    PrintArray(arr, n);

    return 0;
}
