#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int pos = 0; pos <= n - 2; pos++)
    {
        int current = arr[pos];

        // find min element
        int min = pos;
        for (int j = pos; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // swap
        swap(arr[min], arr[pos]);
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);

    cout << "Selection Sort:" << endl;
    for (int a : arr)
        cout << a << endl;

    return 0;
}