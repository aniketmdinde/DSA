#include <iostream>
#include <stack> //STL library for stack
using namespace std;

int main()
{
    stack<string> books; // Declaring a stack

    // Push Operation
    books.push("C++");
    books.push("Python");
    books.push("Java");
    books.push("Perl");

    // Printing
    while (!books.empty())
    {
        cout << books.top() << endl;
        books.pop();
    }
}
