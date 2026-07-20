#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRateToEatBananas(vector<int>& a, int h) {

        int maxi = *max_element(a.begin(), a.end());

        // Try every possible eating speed
        for (int k = 1; k <= maxi; k++) {

            int totalHours = 0;

            // Calculate total hours required at speed k
            for (int i = 0; i < a.size(); i++) {
                totalHours += (a[i] + k - 1) / k;
            }

            // If Koko can finish within h hours
            if (totalHours <= h) {
                return k;
            }
        }

        return -1; // Should never reach here
    }
};

int main() {
    vector<int> a = {7, 15, 6, 3};
    int h = 8;

    Solution obj;
    cout << obj.minimumRateToEatBananas(a, h);

    return 0;
}