#include <iostream>
using namespace std;

void FindSubsets(char *input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0'; // for avoiding garbage getting printed

        if (output[0] == '\0')
            cout << "NULL" << endl;
        else
            cout << output << endl; // print output

        return;
    }

    // recursive case
    // Include char
    output[j] = input[i];
    FindSubsets(input, output, i + 1, j + 1);

    // Exclude char
    FindSubsets(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];

    cin >> input;

    FindSubsets(input, output, 0, 0);

    return 0;
}
