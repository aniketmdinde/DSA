#include <iostream>
using namespace std;

void ClearIthBit(int &n, int i) // pass number by ref to modify it
{
    int mask = ~(1 << i);
    n = (n & mask);
}

void UpdateIthBit(int &n, int i, int val)
{
    ClearIthBit(n, i);
    int mask = val << i;
    n = (n | mask);
}

int main()
{
    int n = 13;
    int i;
    cin >> i;

    UpdateIthBit(n, i, 1);
    cout << n << endl;

    n = 13;
    UpdateIthBit(n, i, 0);
    cout << n << endl;

    return 0;
}
