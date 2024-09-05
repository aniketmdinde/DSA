#include <iostream>
using namespace std;

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

int solveNQueen(int board[][20], int n, int i)
{
    // Base case
    if (i == n)
        return 1;

    // Recursive case
    // Try to place queen in every row
    int ways = 0;

    for (int j = 0; j < n; j++)
    {
        // Check if current position is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            ways += solveNQueen(board, n, i + 1); // add 0 if not solved; add ways if solved

            // backtrack for new configurations
            board[i][j] = 0;
        }
    }
    return ways;
}

int main()
{
    int board[20][20] = {0};

    int n;
    cin >> n;

    cout << "Ways: " << solveNQueen(board, n, 0) << endl;

    return 0;
}
