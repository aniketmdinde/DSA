#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

int GridWays(int m, int n)
{
    int numerator = fact(m + n - 2);
    int denominator = fact(m - 1) + fact(n - 1);

    int ans = numerator / denominator;
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << GridWays(m, n) << endl;

    return 0;
}
