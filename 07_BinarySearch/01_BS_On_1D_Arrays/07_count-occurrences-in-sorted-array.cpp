#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int countOccurrences(vector<int>& arr, int key) {
    int first = firstOccurrence(arr, key);

    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, key);

    return last - first + 1;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};

    cout << countOccurrences(arr, 2);

    return 0;
}