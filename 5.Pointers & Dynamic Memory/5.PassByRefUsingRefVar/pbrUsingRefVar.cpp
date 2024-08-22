#include <iostream>
using namespace std;

// Pass by Value
//  void applyTax(int income)
//  {
//      float tax = 0.10;
//      income = income - income * tax;
//  }

// Pass by Reference
void applyTax(int &income) // note the & symbol indicating reference variable
{
    float tax = 0.10;
    income = income - income * tax;
}

int main()
{
    int income;
    cin >> income;

    applyTax(income);
    cout << income << endl;

    return 0;
}
