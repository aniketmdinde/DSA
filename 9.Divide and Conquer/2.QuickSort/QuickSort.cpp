#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end]; // pivot at last elemet
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[end], arr[i + 1]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    // Base case
    if (start >= end) // if 0 or 1 element
        return;

    // Recursive case
    int pivot_index = partition(arr, start, end);
    QuickSort(arr, start, pivot_index - 1); // LEFT
    QuickSort(arr, pivot_index + 1, end);   // RIGHT
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int start = 0;
    int end = arr.size() - 1;

    QuickSort(arr, start, end);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
