#include <iostream>
using namespace std;

// Global array
string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void NumberSpell(int n)
{
    // Base case
    if (n == 0)
        return;

    int last_digit = n % 10;
    NumberSpell(n / 10);

    // Recursive case
    cout << spell[last_digit] << " ";
}

int main()
{
    int n;
    cin >> n;

    NumberSpell(n);
    cout << endl;
    return 0;
}