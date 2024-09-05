#include <iostream>
using namespace std;

void printBoard(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool canPlace(int board[][20], int n, int i, int j)
{
    // Column check
    for (int k = 0; k < i; k++)
    {
        if (board[k][j] == 1)
            return false;
    }

    // Left Diagonal check
    int x = i;
    int y = j;
    while (x >= 0 and y >= 0)
    {
        if (board[x][y] == 1)
            return false;

        x--;
        y--;
    }

    // Right Diagonal check
    x = i;
    y = j;
    while (x >= 0 and y < n)
    {
        if (board[x][y] == 1)
            return false;

        x--;
        y++;
    }

    // Since no queen found, return true
    return true;
}

bool solveNQueen(int board[][20], int n, int i)
{
    // Base case
    if (i == n)
    {
        // Print board
        printBoard(board, n);
        return true;
    }

    // Recursive case
    // Try to place queen in every row
    for (int j = 0; j < n; j++)
    {
        // Check if current position is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(board, n, i + 1);

            // If remaining grid gives success, then return true
            if (success)
                return true;

            // if fasle, then backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[20][20] = {0};

    int n;
    cin >> n;

    solveNQueen(board, n, 0);

    return 0;
}
