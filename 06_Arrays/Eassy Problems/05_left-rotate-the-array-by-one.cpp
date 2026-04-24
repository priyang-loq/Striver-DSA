#include <bits/stdc++.h>
using namespace std;

/*
    Function: leftRotateByOne
    --------------------------------
    Rotates the array to the left by one position.
    
    Example:
    Input:  [1, 2, 3, 4, 5]
    Output: [2, 3, 4, 5, 1]

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
void leftRotateByOne(vector<int> &nums) {
    int n = nums.size();

    // Edge case: empty or single element array
    if (n <= 1) return;

    int first = nums[0];

    // Shift elements to the left
    for (int i = 0; i < n - 1; i++) {
        nums[i] = nums[i + 1];
    }

    // Place first element at the end
    nums[n - 1] = first;
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Perform left rotation
    leftRotateByOne(nums);

    // Print result
    cout << "Array after left rotation: ";
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}