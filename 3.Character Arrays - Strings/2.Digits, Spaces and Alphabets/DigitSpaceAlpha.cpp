#include <iostream>
using namespace std;

int main()
{
    char ch;
    int alpha = 0;
    int digit = 0;
    int space = 0;

    ch = cin.get();

    while (ch != '\n')
    {
        ch = cin.get();
        if (ch >= '0' && ch <= '9')
            digit++;
        else if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z'))
            alpha++;
        else if (ch == ' ' or ch == '\t')
            space++;
    }

    cout << "Alphabets: " << alpha << endl;
    cout << "Digits: " << digit << endl;
    cout << "Spaces: " << space << endl;

    return 0;
}
