#include <iostream>
using namespace std;

void ClearBitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;

    int mask = a | b;

    n = n & mask;
}

void ReplaceBits(int &n, int m, int i, int j)
{
    ClearBitsInRange(n, i, j);
    int mask = m << i;

    n = n | mask;
}

int main()
{
    int n = 15;
    int m = 2;

    int i, j;
    cin >> i >> j;

    ReplaceBits(n, m, i, j);
    cout << n << endl;

    return 0;
}
