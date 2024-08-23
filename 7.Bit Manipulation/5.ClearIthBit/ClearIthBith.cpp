#include <iostream>
using namespace std;

void ClearIthBit(int &n, int i) // pass number by ref to modify it
{
    int mask = ~(1 << i);
    n = (n & mask);
}

int main()
{
    int n = 13;
    int i;
    cin >> i;

    ClearIthBit(n, i);
    cout << n << endl;

    return 0;
}
