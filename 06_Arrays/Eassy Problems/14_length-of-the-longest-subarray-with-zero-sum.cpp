#include <bits/stdc++.h>
using namespace std;

/*
    Function: solve
    ----------------
    Finds the length of the longest subarray
    having sum equal to 0 using brute force approach.

    Time Complexity  : O(n^3)
    Space Complexity : O(1)
*/

int solve(vector<int> &a)
{
    int n = a.size();

    // Stores maximum length of subarray with sum 0
    int maxLen = 0;

    // Traverse all possible starting indexes
    for (int startIndex = 0; startIndex < n; startIndex++)
    {
        // Traverse all possible ending indexes
        for (int endIndex = startIndex; endIndex < n; endIndex++)
        {
            int currentSum = 0;

            // Calculate sum of current subarray
            for (int i = startIndex; i <= endIndex; i++)
            {
                currentSum += a[i];
            }

            // If sum becomes 0, update maximum length
            if (currentSum == 0)
            {
                maxLen = max(maxLen, endIndex - startIndex + 1);
            }
        }
    }

    return maxLen;
}

int main()
{
    int n;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Function call
    int ans = solve(a);

    // Output result
    cout << "Length of longest subarray with sum 0: "
         << ans << endl;

    return 0;
}