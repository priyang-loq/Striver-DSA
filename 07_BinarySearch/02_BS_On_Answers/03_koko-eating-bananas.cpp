#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRateToEatBananas(vector<int> &a, int h)
    {

        int maxi = *max_element(a.begin(), a.end());
        int left = 1, right = maxi;

        int ans = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int totalHours = 0;

            for (int i = 0; i < a.size(); i++)
            {
                totalHours += (a[i] + mid - 1) / mid;
            }

            if (totalHours <= h)
            {
                ans = mid;       // Store current answer
                right = mid - 1; // Try to find a smaller speed
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> a = {25, 12, 8, 14, 19};
    int h = 5;

    Solution obj;
    cout << obj.minimumRateToEatBananas(a, h);

    return 0;
}