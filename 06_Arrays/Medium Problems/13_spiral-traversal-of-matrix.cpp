#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // Traverse Top Row
        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
        }
        top++;

        // Traverse Right Column
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse Bottom Row
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // Traverse Left Column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    // Print Spiral Order
    for (int x : ans)
    {
        cout << x << " ";
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    spiralMatrix(matrix);

    return 0;
}