#include <iostream>
using namespace std;

void SetIthBit(int &n, int i) // pass number by ref to modify it
{
    int mask = 1 << i;
    n = (n | mask);
}

int main()
{
    int n = 5;
    int i;
    cin >> i;

    SetIthBit(n, i);
    cout << n << endl;

    return 0;
}
