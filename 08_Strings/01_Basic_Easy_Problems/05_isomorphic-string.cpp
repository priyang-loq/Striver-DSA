#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s

        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            char b = t[i];

            // Check s -> t mapping
            if (mp1.count(a) && mp1[a] != b)
                return false;

            // Check t -> s mapping
            if (mp2.count(b) && mp2[b] != a)
                return false;

            // Store mapping
            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};

int main()
{
    string s = "paper";
    string t = "title";

    Solution obj;

    bool ans = obj.isIsomorphic(s, t);

    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}