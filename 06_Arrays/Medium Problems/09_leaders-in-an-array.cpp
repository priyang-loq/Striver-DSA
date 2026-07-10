#include <bits/stdc++.h>
using namespace std;

// Function to find all leaders in the array
vector<int> leaders(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    // Edge case: if the array is empty
    if (n == 0)
        return ans;

    // The last element is always a leader
    int maxi = nums[n - 1];
    ans.push_back(maxi);

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // If the current element is greater than or equal
        // to the maximum element seen so far, it is a leader
        if (nums[i] >= maxi)
        {
            ans.push_back(nums[i]);

            // Update the maximum element
            maxi = nums[i];
        }
    }

    // Leaders were collected from right to left,
    // so reverse the answer to restore the original order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    // Find the leaders in the array
    vector<int> ans = leaders(nums);

    cout << "Leaders in the array are: ";

    // Print all the leaders
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}