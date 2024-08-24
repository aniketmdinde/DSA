#include <iostream>
using namespace std;

int ConvertIntoBinary(int n)
{
    int ans = 0;
    int power = 1;

    while (n > 0)
    {
        int last_bit = (n & 1);

        ans = ans + last_bit * power;

        power = power * 10;
        n = n >> 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << ConvertIntoBinary(n) << endl;

    return 0;
}
