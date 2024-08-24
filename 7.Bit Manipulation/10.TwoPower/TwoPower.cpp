#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0)
        cout << n << " is a Power of 2" << endl;
    else
        cout << n << " is not a Power of 2" << endl;

    return 0;
}
