#include <iostream>
using namespace std;

void FindPermutations(char *input, char *output, int i)
{
    // Base case
    if (input[i] == '\0')
    {
        output[i] = '\0';
        cout << output << endl;
        return;
    }

    // Recursive case
    for (int k = i; input[k] != '\0'; k++)
    {
        swap(input[i], input[k]);
        output[i] = input[i];
        FindPermutations(input, output, i + 1);

        // Backtrack to restore array
        swap(input[i], input[k]);
    }
}

int main()
{
    char input[100];
    char output[100];

    cin >> input;

    FindPermutations(input, output, 0);

    return 0;
}
