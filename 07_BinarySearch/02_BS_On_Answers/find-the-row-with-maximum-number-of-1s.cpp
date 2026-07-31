#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Binary search to find the first index where value >= x
    int lowerBound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n; // Default if x not found

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;      // Possible answer
                high = mid - 1; // Look for smaller index
            }
            else
            {
                low = mid + 1; // Search right half
            }
        }
        return ans;
    }

    // Find row with max number of 1s
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            int cnt_ones = m - lowerBound(matrix[i], m, 1); // 1s = total - index of first 1
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    Solution obj;
    cout << "The row with maximum no. of 1's is: " << obj.rowWithMax1s(matrix, n, m) << '\n';
}
