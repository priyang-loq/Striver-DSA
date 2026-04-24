#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted
bool isSorted(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}