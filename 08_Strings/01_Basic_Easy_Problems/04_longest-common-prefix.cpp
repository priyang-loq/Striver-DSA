#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        int n = strs.size();
        int m = strs[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

int main()
{
    // Predefined input
    vector<string> strs = {"flower", "flow", "flight"};

    Solution obj;

    string ans = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << ans << endl;

    return 0;
}