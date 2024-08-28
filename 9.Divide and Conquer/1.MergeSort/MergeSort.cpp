#include <iostream>
#include <vector>
using namespace std;

// Helper method
void merge(vector<int> &arr, int start, int end)
{
    // we use one array here, since the array is not broken
    // it is basically sorted based on index variable
    // the array is the same

    int mid = (start + end) / 2;

    int i = start;   // start of LEFT
    int j = mid + 1; // start of RIGHT

    vector<int> temp;

    while (i <= mid and j <= end) // loop till one of the array exhausts
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // copy remaining elements into the array from unexhausted array
    // only of these loops will run
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // copy the temp to main array
    int k = 0;
    for (int index = start; index <= end; index++)
    {
        arr[index] = temp[k]; // since temp starts from 0
        k++;
    }
}

// Sorting method
void MergeSort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end) // if there is only 1 element or no element
        return;

    // recursive case
    int mid = (start + end) / 2;
    MergeSort(arr, start, mid);   // LEFT
    MergeSort(arr, mid + 1, end); // RIGHT

    // Once we recursively get solution for LEFT and RIGHT
    merge(arr, start, end); // merge into single sorted array
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int start = 0;
    int end = arr.size() - 1;

    MergeSort(arr, start, end);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}