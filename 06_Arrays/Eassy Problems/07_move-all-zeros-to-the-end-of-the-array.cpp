#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------
Problem: Move all zeroes to the end of the array
         while maintaining the relative order of
         non-zero elements.

Approach:
1. Find the index of the first zero (j).
2. Traverse the array from j+1.
3. Whenever a non-zero element is found:
   - Swap it with nums[j]
   - Increment j (next zero position)

Time Complexity: O(n)
Space Complexity: O(1) (in-place)
------------------------------------------------------
*/

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Find the first zero
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    // If no zero found, array is already valid
    if (j == -1) return;

    // Step 2: Traverse the rest of the array
    for (int i = j + 1; i < n; i++)
    {
        // If current element is non-zero
        if (nums[i] != 0)
        {
            // Swap with the zero at index j
            swap(nums[j], nums[i]);

            // Move j to next position (next zero)
            j++;
        }
    }
}

int main()
{
    int n;

    // Input size of array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Function call
    moveZeroes(nums);

    // Output result
    cout << "Array after moving zeroes: ";
    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}