#include <bits/stdc++.h>
using namespace std;

/*
    Brute Force Approach
    --------------------
    Find the length of the longest subarray
    whose sum is equal to k.

    Time Complexity  : O(N^3)
    Space Complexity : O(1)
*/

class Solution {
public:

    // Function to find longest subarray length
    int longestSubarray(vector<int>& nums, int k) {

        // Size of array
        int n = nums.size();

        // Stores maximum length found
        int maxLength = 0;

        // Select starting index
        for (int startIndex = 0; startIndex < n; startIndex++) {

            // Select ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++) {

                // Calculate current subarray sum
                int currentSum = 0;

                for (int i = startIndex; i <= endIndex; i++) {
                    currentSum += nums[i];
                }

                // Check if subarray sum equals k
                if (currentSum == k) {

                    // Update maximum length
                    maxLength = max(maxLength,
                                    endIndex - startIndex + 1);
                }
            }
        }

        // Return final answer
        return maxLength;
    }
};

int main() {

    int n;

    // Input array size
    cout << "Enter size of array: ";
    cin >> n;

    // Declare vector
    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target sum
    int k;
    cout << "Enter value of k: ";
    cin >> k;

    // Create object of Solution class
    Solution solution;

    // Function call
    int result = solution.longestSubarray(nums, k);

    // Print result
    cout << "\nLength of longest subarray = "
         << result << endl;

    return 0;
}