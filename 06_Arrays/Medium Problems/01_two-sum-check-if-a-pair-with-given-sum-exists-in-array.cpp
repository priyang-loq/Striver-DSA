#include <bits/stdc++.h>
using namespace std;

// Function to return indices of two numbers whose sum equals target
vector<int> twoSum(vector<int>& arr, int target) {

    // Hash map to store:
    // Key   -> Array element
    // Value -> Index of that element
    unordered_map<int, int> mp;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {

        // Find the required complement
        int complement = target - arr[i];

        // If complement exists, return the indices
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        // Store the current element and its index
        // after checking to avoid using the same element twice
        mp[arr[i]] = i;
    }

    // No valid pair found
    return {-1, -1};
}

int main() {

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> ans = twoSum(arr, target);

    if (ans[0] == -1) {
        cout << "No valid pair found." << endl;
    } else {
        cout << "Indices: [" << ans[0] << ", " << ans[1] << "]" << endl;
        cout << "Elements: " << arr[ans[0]] << " + " << arr[ans[1]]
             << " = " << target << endl;
    }

    return 0;
}