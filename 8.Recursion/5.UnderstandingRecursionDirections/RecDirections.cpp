#include <iostream>
using namespace std;

void dec(int n)
{
    if (n == 0)
        return;

    cout << n << endl; // towards the base case
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
        return;

    inc(n - 1);
    cout << n << endl; // away from the base case
}
int main()
{
    int n;
    cin >> n;

    // dec(n);
    inc(n);

    return 0;
}
