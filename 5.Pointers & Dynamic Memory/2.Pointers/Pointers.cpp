#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *xptr = &x;

    cout << &x << endl;
    cout << xptr << endl;

    // Address of pointer variable
    cout << &xptr << endl;

    // Pointer to a pointer variable
    int **xxptr = &xptr;
    cout << xxptr << endl;

    return 0;
}
