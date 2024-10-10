#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s{1, 2, 3, 8, 11, 15, 0};

    int key;
    cin >> key;

    // Search for a key
    if (s.find(key) != s.end())
        cout << key << " is present" << endl;
    else
        cout << key << " is not present" << endl;

    // delete an element
    s.erase(15);

    // insert an element
    s.insert(300);

    // Print all elements
    for (int x : s)
        cout << x << " ";
    cout << endl;

    return 0;
}
