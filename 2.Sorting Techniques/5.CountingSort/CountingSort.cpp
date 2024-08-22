#include <iostream>
#include <vector>
using namespace std;

void counting_sort(int arr[], int n)
{
    // find largest element to find range
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }

    // create count array
    vector<int> freq(largest + 1, 0); // dynamic array of size largest + 1 with all elements initialized to 0

    // Update count array
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        freq[element]++; // for every element in the array update the count of that array in freq array
    }

    // Put the elements as per count in freq array to main array
    int j = 0;                         // index of main array
    for (int i = 0; i <= largest; i++) // i is the index of freq array i.e. the element to be inserted
    {
        while (freq[i] > 0)
        {
            arr[j] = i; // adding the number in main array
            freq[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(int);

    counting_sort(arr, n);

    cout << "Counting Sort:" << endl;
    for (int a : arr)
        cout << a << endl;
    return 0;
}
