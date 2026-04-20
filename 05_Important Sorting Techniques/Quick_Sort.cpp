/*
    Quick Sort Implementation (Using First Element as Pivot)

    - Time Complexity:
        Best/Average: O(n log n)
        Worst: O(n^2)

    - Space Complexity:
        O(log n) (recursion stack)

    - Approach:
        Divide & Conquer
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Partition Function:
    - Chooses first element as pivot
    - Places pivot in its correct sorted position
    - Elements smaller than pivot go left
    - Elements greater go right
*/
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];  // Pivot element
    int i = low;
    int j = high;

    while (i < j)
    {
        // Move i to the right until element > pivot
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        // Move j to the left until element <= pivot
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        // Swap elements if i < j
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot at correct position
    swap(arr[low], arr[j]);

    return j; // Return pivot index
}

/*
    QuickSort Function:
    Recursively sorts left and right partitions
*/
void quicksort(vector<int> &arr, int low, int high)
{
    // Base Case: single or no element
    if (low >= high) return;

    int pivotIndex = partition(arr, low, high);

    // Sort left part
    quicksort(arr, low, pivotIndex - 1);

    // Sort right part
    quicksort(arr, pivotIndex + 1, high);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nUnsorted array:\n";
    for (int x : arr)
        cout << x << " ";

    quicksort(arr, 0, n - 1);

    cout << "\n\nSorted array:\n";
    for (int x : arr)
        cout << x << " ";

    cout << '\n';
    return 0;
}