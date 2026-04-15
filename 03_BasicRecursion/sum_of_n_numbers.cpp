#include <bits/stdc++.h>
using namespace std;

// Function to return sum of first N numbers
int sumN(int n)
{
    // Base case
    if(n == 0) return 0;

    // Return current number + sum of remaining
    return n + sumN(n - 1);
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << "Sum = " << sumN(n);

    return 0;
}