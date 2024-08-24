#include <iostream>
using namespace std;

void ClearLastIBits(int &n, int i)
{
    int mask = (~0 << i);
    // int mask = (-1 << i); //Both same

    n = (n & mask);
}

int main()
{
    int n = 15;
    int i;
    cin >> i;

    ClearLastIBits(n, i);
    cout << n << endl;

    return 0;
}
