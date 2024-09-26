#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s; // store indices of days

    // initialise the problem
    s.push(0);
    span[0] = 1;

    // loop for rest of the days
    for (int i = 1; i < n; i++)
    {
        // topmost element higher than current price
        int current_price = prices[i];
        while (prices[s.top()] <= current_price and !s.empty())
        {
            s.pop();
        }

        if (!s.empty())
        {
            int prev_highest_index = s.top();
            span[i] = i - prev_highest_index;
        }
        else
            span[i] = i + 1;

        // push element in stack
        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[100] = {0};

    stockSpan(prices, n, span);

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
}
