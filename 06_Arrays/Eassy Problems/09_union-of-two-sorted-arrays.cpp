#include <bits/stdc++.h>
using namespace std;

/*
    Class: Solution
    Function: findUnion
    Purpose: Finds the union of two sorted arrays using two-pointer technique
*/
class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> Union;  // Stores final union

        int i = 0, j = 0;   // Two pointers

        // Traverse both arrays
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                // Avoid duplicates
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] < arr1[i]) {
                if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                j++;
            }
            else {
                // If both are equal
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;
                j++;
            }
        }

        // Remaining elements of arr1
        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }

        // Remaining elements of arr2
        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }

        return Union;
    }
};

int main() {
    int n, m;

    // Input size of first array
    cout << "Enter size of first array: ";
    cin >> n;
    int arr1[n];

    // Input elements of first array (sorted)
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Input size of second array
    cout << "Enter size of second array: ";
    cin >> m;
    int arr2[m];

    // Input elements of second array (sorted)
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Create object
    Solution obj;

    // Get union result
    vector<int> result = obj.findUnion(arr1, arr2, n, m);

    // Output result
    cout << "Union of the two arrays is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}