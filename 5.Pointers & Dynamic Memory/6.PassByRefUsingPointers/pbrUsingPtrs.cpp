#include <iostream>
using namespace std;

void watchVideo(int *viewsPtr) // pointer var to store address
{
    // increment view count by 1
    *viewsPtr = *viewsPtr + 1;
}

int main()
{
    int views = 100;
    watchVideo(&views); // passing address

    cout << views << endl;

    return 0;
}
