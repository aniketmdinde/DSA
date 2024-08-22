#include <iostream>
#include <cstring> // include this to use cstyle string functions
using namespace std;

int main()
{
    char a[100] = "apple";
    char b[100];

    // strlen - returns length
    cout << strlen(a) << endl; // takes array to find length of

    // strcpy - copies string from one array to another
    // Note: strcpy(des, src)
    strcpy(b, a); // copy string from a to b
    cout << b << endl;

    // strcmp - compares string
    //  if all matched returns 0
    cout << strcmp(a, b) << endl;

    char c[] = "helloworld";
    cout << strcmp(a, c) << endl; // returns -1 since len of a < c
    cout << strcmp(c, a) << endl; // returns 1 since len of c > a

    // strcat - concatenates 2 strings
    char x[] = "www.";
    char y[] = "aniketdinde.com";
    cout << strcat(x, y) << endl;

    return 0;
}