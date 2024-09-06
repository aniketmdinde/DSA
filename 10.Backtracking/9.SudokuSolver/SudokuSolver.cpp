#include <iostream>
using namespace std;

// Function to check if placing a number is safe
bool isSafe(int mat[9][9], int i, int j, int num, int n)
{
    // Check for row and col
    for (int k = 0; k < n; k++)
    {
        if (mat[k][j] == num || mat[i][k] == num)
            return false;
    }

    // Check for subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == num)
                return false;
        }
    }

    return true;
}

// Function to solve the Sudoku recursively
bool SudokuSolver(int mat[9][9], int i, int j, int n)
{
    // Base case: if we've reached the end of the grid
    if (i == n)
    {
        // Print the solution
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
                cout << mat[x][y] << " ";
            cout << endl;
        }

        return true;
    }

    // Recursive case
    //  If we've reached the end of the row, move to the next row
    if (j == n)
        return SudokuSolver(mat, i + 1, 0, n);

    // If the current cell is already filled, move to the next cell
    if (mat[i][j] != 0)
        return SudokuSolver(mat, i, j + 1, n);

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= n; num++)
    {
        // Check if the number can be placed safely
        if (isSafe(mat, i, j, num, n))
        {
            mat[i][j] = num;
            bool solveSubproblem = SudokuSolver(mat, i, j + 1, n);

            // If we find a solution, return true
            if (solveSubproblem)
                return true;
        }
    }

    // Backtrack if no solution found
    mat[i][j] = 0;
    return false;
}

int main()
{
    int n = 9;
    int mat[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!SudokuSolver(mat, 0, 0, n))
        cout << "No solution exists!";

    return 0;
}
