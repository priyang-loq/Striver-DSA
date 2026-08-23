#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();

        // Remove extra spaces
        int left = 0, right = 0;

        while (right < n)
        {
            while (right < n && s[right] == ' ')
                right++;

            while (right < n && s[right] != ' ')
            {
                s[left++] = s[right++];
            }

            while (right < n && s[right] == ' ')
                right++;

            if (right < n)
                s[left++] = ' ';
        }

        s.resize(left);

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        int start = 0;

        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{
    Solution obj;
    string s = " amazing coding skills ";
    cout << obj.reverseWords(s) << endl;
    return 0;
}