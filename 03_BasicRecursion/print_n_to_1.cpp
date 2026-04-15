#include <bits/stdc++.h>
using namespace std;

// Function to print numbers from N to 1
void printNTo1(int n)
{
    if(n < 1) return;   // Base case

    cout << n << "\n";

    printNTo1(n - 1);   // Recursive call
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    printNTo1(n);

    return 0;
}