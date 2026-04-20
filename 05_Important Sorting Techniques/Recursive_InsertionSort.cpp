#include <bits/stdc++.h>
using namespace std;

// Recursive Insertion Sort using vector
void insertionSort(vector<int> &arr, int i, int n)
{
    // Base Case: if index reaches end
    if (i == n) return;

    int j = i;

    // Shift current element to correct position
    while (j > 0 && arr[j - 1] > arr[j])
    {
        // Swap adjacent elements
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;

        j--; // move left
    }

    // Recursive call for next index
    insertionSort(arr, i + 1, n);
}

int main()
{
    int n;

    // Input: size of vector
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Before sorting
    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call recursive insertion sort
    insertionSort(arr, 0, n);

    // After sorting
    cout << "\nAfter Sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

