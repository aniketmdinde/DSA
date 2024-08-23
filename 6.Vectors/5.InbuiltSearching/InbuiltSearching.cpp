#include <iostream>
#include <vector>
#include <algorithm> //for using inbuilt functions

using namespace std;

int main()
{
    vector<int> arr = {10, 11, 2, 3, 4, 6, 7, 8};
    int key;
    cin >> key;

    vector<int>::iterator it = find(arr.begin(), arr.end(), key);

    if (it != arr.end())
        cout << key << " present at index " << it - arr.begin() << endl;
    else
        cout << "Element not found";

    return 0;
}
