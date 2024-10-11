#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void pairSum(vector<int> arr, int k)
{
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = k - arr[i];

        if (s.find(x) != s.end())
            cout << arr[i] << ", " << x << endl;

        s.insert(arr[i]);
    }
}

int main()
{
    vector<int> arr = {2, 1, 8, 6, -2, 5, 3, 0};
    int k = 8;

    pairSum(arr, k);

    return 0;
}
