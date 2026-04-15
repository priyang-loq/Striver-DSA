#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial using recursion
long long factorial(int n)
{
    // Base case
    if(n == 0 || n == 1) return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    if(n < 0)
    {
        cout << "Factorial not defined for negative numbers";
        return 0;
    }

    cout << "Factorial = " << factorial(n);

    return 0;
}