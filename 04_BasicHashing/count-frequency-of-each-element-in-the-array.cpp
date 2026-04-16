#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100];   // array to store elements
    int n;

    // Taking number of elements as input
    cout << "Enter the number of elements of the array: ";
    cin >> n;

    // Taking array elements as input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map <int,int> mp;   
    // unordered_map to store frequency 
    // key = element, value = count (frequency)
    // NOTE: unordered_map does NOT store elements in sorted order

    // Store frequency of each element
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;   // increase count of arr[i] by 1
    }

    // Printing the result
    cout << "\n--- Results ---\n";

    // Traverse the unordered_map and print element with its frequency
    for (auto it : mp)
    {
        // it.first  -> element
        // it.second -> frequency of that element
        cout << "Frequency of " << it.first  << " is: " 
             << it.second << endl;
    }

    return 0;   // program ends successfully
}