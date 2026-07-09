// This is Better Approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element using an unordered_map
void majorelement(int arr[], int n) {
    // Create an unordered_map to store the frequency of each element
    unordered_map<int, int> map;

    // Traverse the array and count the frequency of each element
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    // Traverse the unordered_map to find the majority element
    for (auto x : map) {
        if (x.second > n / 2) {
            cout << "The majority element is: " << x.first;
        }
    }
}

int main() {
    // Input array
    int arr[] = {1, 1, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to find the majority element
    majorelement(arr, n);

    return 0;
}