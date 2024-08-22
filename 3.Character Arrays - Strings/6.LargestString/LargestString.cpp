#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // no of strings
    int n;
    cin >> n;
    cin.get(); // consumes newline

    char sentence[1000];
    char largest[1000];
    int largest_len = 0;

    while (n--)
    {
        cin.getline(sentence, 1000);

        int len = strlen(sentence);
        if (len > largest_len)
        {
            largest_len = len;
            strcpy(largest, sentence);
        }
    }

    cout << "Largest Sentence: " << largest << endl;

    return 0;
};
