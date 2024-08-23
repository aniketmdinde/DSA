#include <iostream>
using namespace std;

int main()
{
    cout << (5 & 7) << endl;   // And - 5
    cout << (5 | 8) << endl;   // Or - 13
    cout << (5 ^ 7) << endl;   // Ex-or - 2
    cout << (~0) << endl;      // Not - (-1)
    cout << (5 << 2) << endl;  // Left Shift - 20
    cout << (10 >> 1) << endl; // Right Shift - 5

    return 0;
}
