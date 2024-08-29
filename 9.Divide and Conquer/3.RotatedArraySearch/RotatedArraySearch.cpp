#include <iostream>
#include <vector>
using namespace std;

int RotatedArraySearch(vector<int> arr, int key)
{
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key) // Element found
            return mid;

        // LEFT
        if (arr[start] <= arr[mid])
        {
            if (key >= arr[start] and key <= arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else // RIGHT
        {
            if (key >= arr[mid] and key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int key;
    cin >> key;

    cout << RotatedArraySearch(arr, key) << endl;

    return 0;
}
