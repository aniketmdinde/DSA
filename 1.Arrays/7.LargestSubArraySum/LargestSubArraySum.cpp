#include <iostream>
using namespace std;

// Find out the largest sum of the Subarray

// 1. Bruteforce Approach
int largestSubarraySum1(int arr[], int n)
{
    int largest_sum = arr[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int subarray_sum = 0;

            for (int k = i; k <= j; k++)
            {
                subarray_sum += arr[k];
            }

            // check current_sum > largest_sum
            largest_sum = max(largest_sum, subarray_sum);
        }
    }

    return largest_sum;
}

// 2. Prefix Sums Approach
int largestSubarraySum2(int arr[], int n)
{
    int prefix[n] = {0};

    prefix[0] = arr[0]; // first sum is same
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // largest sum logic
    int largest_sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // if i=0: subarray_sum = prefix[j] since it start from 0 to j
            // if i>0: subarray_sum = prefix[j] - prefix[i-1]
            int subarray_sum = (i > 0) ? (prefix[j] - prefix[i - 1]) : (prefix[j]);

            // check current_sum > largest_sum
            largest_sum = max(largest_sum, subarray_sum);
        }
    }

    return largest_sum;
}

// 3. Kadane's Algorithm Approach
int largestSubarraySum3(int arr[], int n)
{
    int current_sum = 0;
    int largest_sum = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum = current_sum + arr[i];

        if (current_sum < 0)
            current_sum = 0;

        largest_sum = max(largest_sum, current_sum);
    }

    return largest_sum;
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Largest Sum Array Sum 1: " << largestSubarraySum1(arr, n) << endl;
    cout << "Largest Sum Array Sum 2: " << largestSubarraySum2(arr, n) << endl;
    cout << "Largest Sum Array Sum 3: " << largestSubarraySum3(arr, n) << endl;

    return 0;
}