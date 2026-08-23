#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";
        int n = s.size();
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (counter > 0)
                {
                    result += s[i];
                }
                counter++;
            }
            else if (s[i] == ')')
            {
                counter--;
                if (counter > 0)
                {
                    result += s[i];
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "(()())(())";

    Solution sol;
    string ans = sol.removeOuterParentheses(s);

    cout << "The result is: " << ans << endl;
    return 0;
}