#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int times = 1; times <= n - 1; times++)
    {
        // repeated swapping
        for (int j = 0; j <= n - 1 - times; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, 12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);

    cout << "Bubble Sort:" << endl;
    for (int a : arr)
        cout << a << endl;

    return 0;
}