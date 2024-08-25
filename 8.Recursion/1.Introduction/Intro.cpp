#include <iostream>
using namespace std;

void GoHome(int x, int Home)
{
    if (x == Home)
    {
        cout << "Reached Home" << endl;
        return;
    }

    x = x + 1;
    GoHome(x, Home);
}

int main()
{
    int x = 1;
    int Home = 10;

    GoHome(x, Home);
    return 0;
}