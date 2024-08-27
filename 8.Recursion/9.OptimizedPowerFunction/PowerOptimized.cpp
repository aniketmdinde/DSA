#include <iostream>
using namespace std;

int powerOptimized(int a, int n)
{
    if (n == 0)
        return 1;

    int subProblem = powerOptimized(a, n / 2);
    int subProblemSq = subProblem * subProblem;

    if (n & 1) // check if odd number
        return a * subProblemSq;

    return subProblemSq;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << powerOptimized(a, n) << endl;

    return 0;
}
