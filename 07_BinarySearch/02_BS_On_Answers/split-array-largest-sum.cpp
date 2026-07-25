#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if the array can be split into at most k subarrays
    bool possible(vector<int>& nums, int k, int maxSum) {
        int count = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                count++;
                currentSum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};