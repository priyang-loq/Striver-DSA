#include <bits/stdc++.h>
using namespace std;

// Function to print numbers from 1 to N
void print1ToN(int i, int n)
{
    if(i > n) return;   // Base case

    cout << i << "\n";

    print1ToN(i + 1, n);  // Recursive call
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    print1ToN(1, n);

    return 0;
}