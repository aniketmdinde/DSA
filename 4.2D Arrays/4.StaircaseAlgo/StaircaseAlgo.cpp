#include <iostream>
using namespace std;

pair<int, int> StaircaseSearch(int arr[][4], int n, int m, int key) // return pair of indices
{
    // element not present return {-1,-1}
    if (key < arr[0][0] or key > arr[n - 1][m - 1])
        return {-1, -1};

    // Staircase search
    int i = 0;
    int j = m - 1;

    while (i <= n - 1 and j >= 0)
    {
        if (arr[i][j] == key)
            return {i, j};
        else if (arr[i][j] > key)
            j--; // move backwards
        else
            i++; // move downwards
    }

    return {-1, -1}; // element not found
}

int main()
{
    int arr[][4] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};

    int n = 4;
    int m = 4;
    int key = 33;

    pair<int, int> coords = StaircaseSearch(arr, n, m, key);
    cout << coords.first << " " << coords.second << endl;

    return 0;
}
