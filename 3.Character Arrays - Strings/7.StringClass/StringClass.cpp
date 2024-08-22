#include <iostream>
#include <string> // include this to use string utilities
#include <vector>
using namespace std;

int main()
{
    // string s; // Dynamic array
    // s = "hello world";
    // cout << s << endl;

    // Constructor based initialization
    // string a("Good morning");
    // cout << a << endl;

    // Taking input
    // string z;
    // getline(cin, z);
    // cout << z << endl;

    // getline(cin, z, '.'); // Optional Parameter of giving and terminate string symbol
    // cout << z << endl;

    // Iterating over strings
    // for (char ch : a)
    //     cout << ch << ", ";

    // array or vector of strings
    int n = 5;
    vector<string> s_arr;
    string temp;

    while (n--)
    {
        getline(cin, temp);
        s_arr.push_back(temp);
    }

    cout << "\nSentences: " << endl;
    for (string s : s_arr)
        cout << s << endl;

    return 0;
}