#include <bits/stdc++.h>
using namespace std;

/* ===================== SELECTION SORT ===================== */
void selectionSort(int arr[], int n)
{
    // Traverse the array
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;  // Assume current index is minimum

        // Find the minimum element in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        // Swap minimum element with current position
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    // Output result
    cout << "\n🔹 Selection Sort Result:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


/* ===================== BUBBLE SORT ===================== */
void bubbleSort(int arr[], int n)
{
    // Traverse from last to first
    for (int i = n - 1; i > 0; i--)
    {
        int didSwap = 0; // Optimization flag

        for (int j = 0; j <= i - 1; j++)
        {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = 1;
            }
        }

        // If no swaps → array already sorted
        if (didSwap == 0)
            break;
    }

    // Output result
    cout << "\n🔹 Bubble Sort Result:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


/* ===================== INSERTION SORT ===================== */
void insertionSort(int arr[], int n)
{
    // Start from second element
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];   // Element to be placed
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }

    // Output result
    cout << "\n🔹 Insertion Sort Result:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


/* ===================== MAIN FUNCTION ===================== */
int main()
{
    int n;
    int arr[100];

    cout << "================ Sorting Algorithms Demo ================\n";

    // Input size
    cout << "Enter number of elements: ";
    cin >> n;

    // Input elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Create copies so each sort works on same data
    int arr1[100], arr2[100], arr3[100];

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    // Call sorting functions
    selectionSort(arr1, n);
    bubbleSort(arr2, n);
    insertionSort(arr3, n);

    cout << "\n================ Execution Complete ================\n";

    return 0;
}