#include <iostream>
using namespace std;

int GridWays(int i, int j, int m, int n) // start cell: (i,j) ; target cell: (m,n)
{
    // Base case
    if (i == m - 1 and j == n - 1)
        return 1;

    if (i >= m or j >= n)
        return 0;

    // Recursive case
    int ans = GridWays(i + 1, j, m, n) + GridWays(i, j + 1, m, n);
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << GridWays(0, 0, m, n) << endl;

    return 0;
}
