#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b; // sort lexiographically
    else
        return a.length() < b.length(); // sort by size
}

void FindSubsets(char *input, char *output, int i, int j, vector<string> &list)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';

        if (output[0] == '\0')
            list.push_back("null");
        else
        {
            string temp(output);
            list.push_back(temp);
        }

        return;
    }

    // recursive case
    // Include
    output[j] = input[i];
    FindSubsets(input, output, i + 1, j + 1, list);

    // Exclude
    FindSubsets(input, output, i + 1, j, list);
}

int main()
{
    char input[100];
    char output[100];
    vector<string> list;

    cin >> input;
    FindSubsets(input, output, 0, 0, list);
    sort(list.begin(), list.end(), compare);

    // Printing
    for (string l : list)
        cout << l << " ";
    cout << endl;

    return 0;
}
