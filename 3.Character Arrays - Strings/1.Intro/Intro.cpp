#include <iostream>
#include <cstring> //include for using inbuilt string functions
using namespace std;

int main()
{
    // char a[] = {'a', 'b', 'c', 'd'}; //Initialization without null
    // char a[] = {'a', 'b', 'c', 'd', '\0'}; //Initialization with null
    // char a[] = "abcdef"; // string causes automatic inclusion of null char at the end

    // cout << a << endl; // char arrays can be printed directly

    // Inbuilt functions
    // cout << strlen(a) << endl; // returns length (no of visible chars)
    // cout << sizeof(a) << endl; // returns size (including null char)

    // Taking array as input
    // char b[100];
    // cin >> b;
    // cout << "Array contains: " << b << endl;

    // Using cin.get()
    // char b[100];
    // char temp;
    // int index = 0;
    // while (temp != '\n') // if newline char then stop
    // {
    //     temp = cin.get(); // reads one char from input buffer
    //     b[index] = temp;
    //     index++;
    // }
    // b[index - 1] = '\0'; // replacing newline char with null char

    // cout << "Array contains: " << b << endl;

    // Using cin.getline()
    char b[100];
    cin.getline(b, 100); // arguments - array , max input size

    cout << "Array contains: " << b << endl;

    return 0;
}
