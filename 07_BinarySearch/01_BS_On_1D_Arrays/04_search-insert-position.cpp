#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the insert position of x in a sorted array
    int searchInsert(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n; // Default: insert at the end

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;        // Potential answer
                high = mid - 1;   // Search on the left
            } else {
                low = mid + 1;    // Search on the right
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;

    Solution obj;
    int index = obj.searchInsert(arr, x);

    cout << "The index is: " << index << endl;

    return 0;
}