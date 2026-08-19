#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int index = -1;
        int prevCount = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > prevCount)
            {
                prevCount = count;
                index = i;
            }
        }
        return index;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1}, {0, 0, 1}, {1, 1, 1}};
    int n = 3, m = 3;

    Solution obj;
    cout << "The row with maximum no. of 1's is: " << obj.rowWithMax1s(matrix, n, m) << '\n';
    return 0;
}