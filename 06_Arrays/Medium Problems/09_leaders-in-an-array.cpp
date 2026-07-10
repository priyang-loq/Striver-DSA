#include <bits/stdc++.h>
using namespace std;

// Function to find leaders in the array
vector<int> leaders(vector<int> &nums)
{
    vector<int> ans;

    // Check every element
    for (int i = 0; i < nums.size(); i++)
    {
        bool leader = true;

        // Compare with all elements to its right
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                leader = false;
                break;
            }
        }

        // If still a leader, add to answer
        if (leader)
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    vector<int> ans = leaders(nums);

    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}