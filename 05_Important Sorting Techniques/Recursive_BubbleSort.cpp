/*
    Recursive Bubble Sort (Optimized with Early Exit)

    Approach:
    - Outer loop is handled using recursion.
    - Inner loop is handled using a standard for loop.
    - After each pass, the largest element moves to its correct position.
    - If no swaps occur in a pass, the array is already sorted (early exit).

    Time Complexity:
    - Best Case: O(n)        (already sorted, early exit)
    - Average Case: O(n^2)
    - Worst Case: O(n^2)

    Space Complexity:
    - O(n) due to recursion stack

    Author: Priyangshu Das
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function: rec
    ----------------------------
    Sorts the array using recursive Bubble Sort.

    Parameters:
    - arr : reference to vector<int> (array to sort)
    - i   : represents the last index of the current pass
*/
void rec(vector<int> &arr, int i)
{
    // Base case: no more passes needed
    if (i == 0) return;

    bool didSwap = false; // flag to track if any swap happens

    // Inner loop: perform one pass of Bubble Sort
    for (int j = 0; j <= i - 1; j++)
    {
        // Swap if elements are in wrong order
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            didSwap = true;
        }
    }

    // If no swaps happened, array is already sorted
    if (!didSwap) return;

    // Recursive call for the remaining unsorted portion
    rec(arr, i - 1);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call recursive bubble sort
    rec(arr, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    cout << endl;

    return 0;
}