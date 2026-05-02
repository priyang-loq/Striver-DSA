#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Find Maximum Consecutive 1's
    Approach: Linear Traversal
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    // Function to find maximum consecutive 1's in an array
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int cnt = 0;   // current consecutive 1's count
        int maxi = 0;  // maximum consecutive 1's

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;              // increment count if 1
            } else {
                cnt = 0;            // reset if 0
            }
            maxi = max(maxi, cnt);  // update max
        }

        return maxi;
    }
};

int main() {
    int n;

    // Take input size
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Take array input
    cout << "Enter elements (0s and 1s only): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create object
    Solution obj;

    // Get result
    int ans = obj.findMaxConsecutiveOnes(nums);

    // Output result
    cout << "Maximum consecutive 1's: " << ans << endl;

    return 0;
}