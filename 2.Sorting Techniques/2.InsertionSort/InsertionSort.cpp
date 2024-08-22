#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i]; // element in unsorted part to be positioned
        int prev = i - 1;

        // loop to find the right index where the element to be positioned will be inserted
        while (prev >= 0 and arr[prev] > current) // run the loop until prev reaches
        {                                         //  the end or element in the sorted part is greater than current element
            arr[prev + 1] = arr[prev];            // move the elements back
            prev--;
        }

        arr[prev + 1] = current; // positioned the current element
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    insertion_sort(arr, n);

    cout << "Insertion Sort:" << endl;
    for (int a : arr)
        cout << a << endl;

    return 0;
}