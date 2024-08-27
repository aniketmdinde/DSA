#include <iostream>
using namespace std;

void bubbleSortRec1(int arr[], int n)
{
    // base case
    if (n == 1)
        return; // one element is sorted

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    }

    // recursive case - outer loop
    bubbleSortRec1(arr, n - 1);
}

void bubbleSortRec2(int arr[], int n, int j)
{
    // base case
    if (n == 1)
        return; // one element is sorted

    if (j == n - 1)
    {
        // reduce problem size and reset j
        bubbleSortRec2(arr, n - 1, 0);
        return;
    }

    if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);

    // recursive case - inner loop
    // move j forward for swapping
    bubbleSortRec2(arr, n, j + 1);
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, 12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    // bubbleSortRec1(arr, n);
    bubbleSortRec2(arr, n, 0);

    cout << "Bubble Sort:" << endl;
    for (int a : arr)
        cout << a << endl;

    return 0;
}
