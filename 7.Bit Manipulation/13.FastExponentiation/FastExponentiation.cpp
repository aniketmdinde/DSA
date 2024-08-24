#include <iostream>
using namespace std;

int fastExpo(int a, int n)
{
    int ans = 1;

    while (n > 0)
    {
        int last_bit = (n & 1); // tells if last bit is 0 or 1

        if (last_bit)
        {
            ans = ans * a; // multiplying power only if last bit is set
        }

        a = a * a;  // generating power
        n = n >> 1; // right shifting for iterating
    }

    return ans;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << fastExpo(a, n) << endl;

    return 0;
}