#include <iostream>
using namespace std;

int **create2DArray(int rows, int cols)
{
    // Creating variable to store row array
    int **arr = new int *[rows];

    // Allocate memory for each row
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // Initializing array
    int val = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = val;
            val++;
        }
    }

    return arr;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int **arr = create2DArray(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }

    return 0;
}
