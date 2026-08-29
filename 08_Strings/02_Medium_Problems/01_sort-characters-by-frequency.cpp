#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], (char)i});
            }
        }

        string ans = "";

        while (!pq.empty()) {
            int frequency = pq.top().first;
            char character = pq.top().second;
            pq.pop();

            for (int i = 0; i < frequency; i++) {
                ans += character;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s = "tree";

    string result = sol.frequencySort(s);

    cout << result;

    return 0;
}