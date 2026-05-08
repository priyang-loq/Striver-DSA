#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the length of the longest subarray with sum = k
    int longestSubarray(vector<int> &nums, int k)
    {
        // Size of array
        int n = nums.size();

        // Left and right pointers for sliding window
        int left = 0, right = 0;

        // Variable to store current window sum
        int sum = nums[0];

        // Variable to store maximum length
        int maxLen = 0;

        // Traverse the array
        while (right < n)
        {
            // Shrink the window if sum becomes greater than k
            while (left <= right && sum > k)
            {
                sum -= nums[left];
                left++;
            }

            // If current sum equals k
            if (sum == k)
            {
                // Update maximum length
                maxLen = max(maxLen, right - left + 1);
            }

            // Move right pointer
            right++;

            // Add next element into the window
            if (right < n)
            {
                sum += nums[right];
            }
        }

        // Return the answer
        return maxLen;
    }
};

int main()
{
    // Taking size of array as input
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Declaring vector
    vector<int> nums(n);

    // Taking array elements as input
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Taking target sum as input
    int k;
    cout << "Enter target sum: ";
    cin >> k;

    // Creating object of Solution class
    Solution sol;

    // Function call
    int ans = sol.longestSubarray(nums, k);

    // Printing the result
    cout << "Length of longest subarray having sum "
         << k << " is: " << ans << endl;

    return 0;
}