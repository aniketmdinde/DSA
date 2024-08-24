#include <iostream>
using namespace std;

void ClearBitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;

    int mask = a | b;

    n = n & mask;
}

int main()
{
    int n = 31;

    int i, j;
    cin >> i >> j;

    ClearBitsInRange(n, i, j);
    cout << n << endl;

    return 0;
}
