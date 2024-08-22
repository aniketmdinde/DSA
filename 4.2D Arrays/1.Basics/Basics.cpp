#include <iostream>
using namespace std;

// Pass by reference
void print_arr(int arr[][100], int n, int m) // passing 2D array, number of rows is optional but no of columns is important
{
    cout << "Printing Array" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[100][100];
    int n, m; // n rows and m columns
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << i << "," << j << ": ";
            cin >> arr[i][j];
        }
    }

    print_arr(arr, n, m);

    return 0;
}
