/*
    Quick Sort Implementation (Lomuto Partition Scheme)

    Time Complexity:
        Best Case    : O(n log n)
        Average Case : O(n log n)
        Worst Case   : O(n^2)

    Space Complexity:
        O(log n) (Recursion Stack)

    Approach:
        - Divide and Conquer
        - Uses the last element as the pivot.
        - Partitions the array so that:
            * Elements <= pivot are placed on the left.
            * Elements > pivot are placed on the right.
        - Recursively sorts both partitions.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to partition the array using the last element as pivot.
    Returns the correct index of the pivot after partitioning.
*/
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int index = low - 1;

    // Place all elements smaller than or equal to the pivot on the left
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(arr[index], arr[j]);
        }
    }

    // Place the pivot in its correct sorted position
    index++;
    swap(arr[index], arr[high]);

    return index;
}

/*
    Quick Sort Function

    Recursively sorts:
    1. Left partition
    2. Right partition
*/
void quickSort(vector<int> &arr, int low, int high)
{
    // Base Case
    if (low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    // Sort left half
    quickSort(arr, low, pivotIndex - 1);

    // Sort right half
    quickSort(arr, pivotIndex + 1, high);
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

    cout << "\nUnsorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\n\nSorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}