#include <bits/stdc++.h>
using namespace std;

// Function to reverse array using recursion
void reverseArray(int i, int arr[], int n)
{
    // Base case: stop when middle is reached
    if(i >= n / 2) return;

    // Swap elements
    swap(arr[i], arr[n - i - 1]);

    // Recursive call
    reverseArray(i + 1, arr, n);
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseArray(0, arr, n);

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}