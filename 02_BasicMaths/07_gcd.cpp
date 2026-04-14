#include <bits/stdc++.h>
using namespace std;

// Function to find GCD using Euclidean Algorithm
void findGcd(int a, int b)
{
    // Run until one becomes 0
    while(a > 0 && b > 0)
    {
        if(a > b)
        {
            a = a % b; // reduce a
        }
        else
        {
            b = b % a; // reduce b
        }
    }

    // Print result
    if(a == 0)
        cout << "GCD is: " << b;
    else
        cout << "GCD is: " << a;
}

int main()
{
    int a, b;
    cin >> a >> b;

    findGcd(a, b);
    return 0;
}