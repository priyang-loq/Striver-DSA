#include<bits/stdc++.h>
using namespace std;

// Function to find the second smallest and second largest elements in the array
void getElements(int arr[], int n)
{
    // Edge case when the array has less than 2 elements
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // Print -1 for both second smallest and second largest if the array has less than 2 elements
    
    // Sort the array to easily find the second smallest and second largest elements
    sort(arr, arr + n);

    // Second smallest element is at index 1 after sorting
    int small = arr[1]; 

    // Second largest element is at index n-2 after sorting
    int large = arr[n - 2]; 

    // Output the second smallest and second largest elements
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}

int main()
{
    // Initialize the array with elements
    int arr[] = {1, 2, 4, 6, 7, 5};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call the function to find and print the second smallest and second largest elements
    getElements(arr, n);

    return 0;
}