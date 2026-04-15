#include <bits/stdc++.h>
using namespace std;

// Recursive function to print name N times
void printName(int i, int n)
{
    // Base case: stop when i exceeds n
    if(i > n) return;

    cout << "Priyang\n";

    // Recursive call
    printName(i + 1, n);
}

int main()
{
    int n;
    cout << "Enter how many times you want to print your name: ";
    cin >> n;

    printName(1, n);

    return 0;
}