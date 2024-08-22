#include <iostream>
#include "vector.h" //using user defined header file from same directory

using namespace std;

int main()
{
    Vector<int> v(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    Vector<char> s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');

    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;

    return 0;
}
