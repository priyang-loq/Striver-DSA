#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count subarrays with XOR equal to B
    int countSubarraysXOR(vector<int>& A, int B) {
        // Initialize count of valid subarrays
        int count = 0;
        // Traverse all starting points
        for (int i = 0; i < A.size(); i++) {
            // Maintain xor of current subarray
            int xorVal = 0;
            // Extend subarray till end
            for (int j = i; j < A.size(); j++) {
                // Update xor
                xorVal ^= A[j];
                // If xor equals B, increment count
                if (xorVal == B) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    // Input array
    vector<int> A = {4, 2, 2, 6, 4};
    // Target xor
    int B = 6;

    Solution sol;
    cout << sol.countSubarraysXOR(A, B) << endl;
    return 0;
}
