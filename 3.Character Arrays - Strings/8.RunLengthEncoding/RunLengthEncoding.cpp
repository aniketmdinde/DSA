#include <iostream>
#include <string>
using namespace std;

string compressString(string str)
{
    int n = str.length();
    string output;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 and str[i + 1] == str[i]) // we go loop till end of string and check if next char is same as the current
        {
            count++;
            i++;
        }

        output += str[i];           // letter that is repeating
        output += to_string(count); // no of times letter is repeating
    }

    if (output.length() > str.length())
        return str;

    return output;
}

int main()
{
    string s1 = "aaabbccddee";
    cout << compressString(s1) << endl;

    string s2 = "abcd";
    cout << compressString(s2) << endl;

    return 0;
}