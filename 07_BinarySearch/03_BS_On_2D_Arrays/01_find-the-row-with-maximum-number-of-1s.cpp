#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int index = -1;
        int numberofOnes = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int low = 0;
            int high = m - 1;
            int firstOneIndex = m;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (matrix[i][mid] == 1)
                {
                    firstOneIndex = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            int ones = m - firstOneIndex;

            if (ones > numberofOnes)
            {
                numberofOnes = ones;
                index = i;
            }
        }

        return index;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {0, 0, 1},
        {1, 1, 1}};

    int n = 3, m = 3;

    Solution obj;

    cout << "The row with maximum no. of 1's is: "
         << obj.rowWithMax1s(matrix, n, m) << '\n';

    return 0;
}