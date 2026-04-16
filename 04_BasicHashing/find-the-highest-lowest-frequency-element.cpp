#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100];   
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

    // Store frequency of each element
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;   // increase count of arr[i]
    }

    cout << "\n--- Results ---\n";

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Traverse the map to find max and min frequency elements
    for (auto it : mp)
    {
        int element = it.first;   // current element
        int count = it.second;    // its frequency

        // Update maximum frequency element
        if (count > maxFreq) {
            maxFreq = count;
            maxEle = element;
        }

        // Update minimum frequency element
        if (count < minFreq) {
            minFreq = count;
            minEle = element;
        }
    }

    // Print final results with frequency
    cout << "Highest frequency element: " << maxEle 
         << " (Frequency: " << maxFreq << ")\n";

    cout << "Lowest frequency element: " << minEle 
         << " (Frequency: " << minFreq << ")\n";

    return 0;   // program ends successfully
}