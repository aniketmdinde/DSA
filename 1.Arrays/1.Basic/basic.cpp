#include <iostream>
using namespace std;

int main()
{
    int marks[10]; // declaration

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << ", ";
    }
    cout << endl;

    // int marks[10] = {0}; // initialization list
    // int marks[10] = {3}; // initialization list
    // marks[0] = -1;       // assigning a value
    // // printing whole array
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << marks[i] << ", ";
    // }
    // cout << endl;

    return 0;
}
