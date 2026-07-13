#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------
    1. Find the element at (r, c) in Pascal's Triangle
    Time Complexity : O(c)
    Space Complexity: O(1)
------------------------------------------------------------*/

long long findPascalElement(int r, int c)
{
    // Element = C(r-1, c-1)

    int n = r - 1;
    int k = c - 1;

    long long result = 1;

    for (int i = 0; i < k; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }

    return result;
}

/*------------------------------------------------------------
    2. Generate the Nth row of Pascal's Triangle
    Time Complexity : O(N)
    Space Complexity: O(N)
------------------------------------------------------------*/

vector<long long> getNthRow(int N)
{
    vector<long long> row;

    long long val = 1;
    row.push_back(val);

    for (int k = 1; k < N; k++)
    {
        val = val * (N - k) / k;
        row.push_back(val);
    }

    return row;
}

/*------------------------------------------------------------
    3. Generate the complete Pascal's Triangle
    Time Complexity : O(N²)
    Space Complexity: O(1) (excluding output)
------------------------------------------------------------*/

// Function to generate a single row
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;

    ansRow.push_back(1);

    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col) / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

// Function to generate the complete Pascal's Triangle
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 1; i <= numRows; i++)
    {
        triangle.push_back(generateRow(i));
    }

    return triangle;
}

int main()
{
    /*--------------------------------------------------------
        Uncomment ONLY ONE section at a time.
    --------------------------------------------------------*/

    // ==========================
    // 1. Find Pascal Element
    // ==========================

    /*
    int r, c;
    cin >> r >> c;

    cout << findPascalElement(r, c);
    */

    // ==========================
    // 2. Generate Nth Row
    // ==========================

    /*
    int N;
    cin >> N;

    vector<long long> row = getNthRow(N);

    for (auto x : row)
    {
        cout << x << " ";
    }
    */

    // ==========================
    // 3. Generate Complete Triangle
    // ==========================

    int numRows;
    cin >> numRows;

    vector<vector<int>> triangle = generate(numRows);

    for (auto row : triangle)
    {
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}