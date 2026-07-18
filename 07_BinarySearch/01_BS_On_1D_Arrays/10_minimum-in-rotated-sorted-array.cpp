#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        // Initialize answer with a large number
        int minVal = INT_MAX;
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            minVal = min(minVal, nums[mid]);
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return minVal;
    }
};

int main()
{

    // Input array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.findMin(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}
