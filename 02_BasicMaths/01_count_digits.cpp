#include <bits/stdc++.h>
using namespace std;

// Function to count number of digits in a number
int countDigits(int n) {
    int count = 0;

    // Keep dividing number until it becomes 0
    while (n > 0) {
        n = n / 10;
        count++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Total digits: " << countDigits(n);
    return 0;
}