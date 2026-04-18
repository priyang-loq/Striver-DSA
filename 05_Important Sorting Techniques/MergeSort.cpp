#include <bits/stdc++.h>
using namespace std;

/*
    Function: merge
    ----------------
    Merges two sorted halves of the array:
    Left half  -> [low ... mid]
    Right half -> [mid+1 ... high]

    It uses a temporary vector to store sorted elements
    and then copies them back to the original array.
*/
void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;        // starting index of left half
    int right = mid + 1;   // starting index of right half

    vector<int> temp;      // temporary array to store merged result

    // Compare elements from both halves and store smaller one
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Store remaining elements of left half (if any)
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Store remaining elements of right half (if any)
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/*
    Function: mergesort
    --------------------
    Recursively divides the array into halves
    until each subarray has one element,
    then merges them back in sorted order.
*/
void mergesort(vector<int> &arr, int low, int high)
{
    // Base case: single element is already sorted
    if (low >= high) return;

    int mid = (low + high) / 2;

    // Sort left half
    mergesort(arr, low, mid);

    // Sort right half
    mergesort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

int main()
{
    int n;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);   // initialize vector with size n

    // Input elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call merge sort
    mergesort(arr, 0, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}