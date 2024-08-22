#include <iostream>
using namespace std;

int main()
{
    // char sentence[100];
    // cin.getline(sentence, 100); // 100 tells the max input sentence array can take
    // cout << "Sentence: " << sentence << endl;

    // reading a paragraph
    char sentence[100];
    cin.getline(sentence, 100, '#'); // 3rd parameter is optional => stopping symbol
    cout << "Paragraph: \n"
         << sentence << endl;

    return 0;
}
