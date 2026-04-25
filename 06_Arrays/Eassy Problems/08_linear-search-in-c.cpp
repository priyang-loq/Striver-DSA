#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------
Problem: Linear Search

Goal:
Search for a given element in an array and return its index.

Approach:
- Traverse the array from start to end
- If element is found → print index and return
- If not found after loop → print "not found"

Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------
*/

void linearSearch(vector<int> &nums, int element)
{
    int n = nums.size();

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element)
        {
            cout << "Element " << element 
                 << " found at index: " << i << endl;
            return; // stop after finding
        }
    }

    // If element not found
    cout << "Element " << element << " not found" << endl;
}

int main()
{
    int n, element;

    // Input size
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Input elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Input target element
    cout << "Enter the element to find: ";
    cin >> element;

    // Function call
    linearSearch(nums, element);

    return 0;
}