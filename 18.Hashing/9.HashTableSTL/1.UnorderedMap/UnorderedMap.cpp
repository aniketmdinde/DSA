#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> menu; // key - string, value- int

    // Insertion
    menu["maggi"] = 15;
    menu["coldDrink"] = 20;
    menu["Dosa"] = 99;

    // Update
    menu["Dosa"] += 10;

    // Iterate over all key value pairs
    for (pair<string, int> item : menu) // menu returns a pair
        cout << item.first << " - " << item.second << endl;

    cout << endl;

    // Search
    string item;
    cin >> item;

    if (menu.count(item) == 0) // count function tells if an item is present in hash table - 0 or 1
        cout << item << " is not available!" << endl;
    else
        cout << item << " is available and its cost is " << menu[item] << endl;

    // Deletion
    cout << "Dosa erased" << endl;
    menu.erase("Dosa");

    cout << endl;

    for (pair<string, int> item : menu)
        cout << item.first << " - " << item.second << endl;

    return 0;
}