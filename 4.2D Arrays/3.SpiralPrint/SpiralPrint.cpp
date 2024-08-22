#include <iostream>
using namespace std;

void printSpiral(int arr[][4], int n, int m)
{
    int startRow = 0;
    int endCol = m - 1;
    int endRow = n - 1;
    int startCol = 0;

    while (startCol <= endCol and startRow <= endRow)
    {
        // printing iteration
        for (int col = startCol; col <= endCol; col++)
            cout << arr[startRow][col] << " ";

        for (int row = startRow + 1; row <= endRow; row++)
            cout << arr[row][endCol] << " ";

        for (int col = endCol - 1; col >= startCol; col--)
        {
            if (startRow == endRow)
                break; // avoiding double printing

            cout << arr[endRow][col] << " ";
        }

        for (int row = endRow - 1; row >= startRow + 1; row--)
        {
            if (startCol == endCol)
                break; // avoiding double printing

            cout << arr[row][startCol] << " ";
        }

        // updating variables
        startRow++;
        endCol--;
        endRow--;
        startCol++;
    }
}

int main()
{
    int arr[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int n = 4, m = 4;
    printSpiral(arr, 4, 4);

    return 0;
}
