#include <iostream>
using namespace std;

int main()
{
    char numbers[][10] = {
        "one", // numbers[0]
        "two", // numbers[1]
        "three",
        "four",
        "five",
    }; // array of char arrays

    cout << numbers[4] << endl;
    cout << numbers[4][2] << endl;

    for (int i = 0; i < 5; i++)
        cout << numbers[i] << endl;

    return 0;
}
