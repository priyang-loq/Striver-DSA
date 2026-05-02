#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Author: Priyangshu Das
Problem: Find the single non-repeating element in an array
Approach: XOR (Bit Manipulation)

Concept:
- a ^ a = 0
- a ^ 0 = a
- XOR cancels duplicate elements

Time Complexity: O(n)
Space Complexity: O(1)
---------------------------------------------------------
*/

class Solution {
public:
    int getSingleElement(vector<int>& arr) {
        int xorr = 0;

        // XOR all elements
        for (int num : arr) {
            xorr ^= num;
        }

        return xorr;
    }
};

int main() {
    int n;

    // Input size
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    // Function call
    int ans = obj.getSingleElement(arr);

    // Output
    cout << "Single non-repeating element: " << ans << endl;

    return 0;
}