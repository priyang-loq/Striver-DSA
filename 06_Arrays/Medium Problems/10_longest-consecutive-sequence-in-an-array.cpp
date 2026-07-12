#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest consecutive sequence
int longestConsecutive(vector<int> &nums)
{
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = nums[i] - nums[j];
            if (diff == -1 || diff == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    // Input array
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Function call
    int ans = longestConsecutive(nums);

    // Output
    cout << "Length of Longest Consecutive Sequence: " << ans << endl;

    return 0;
}