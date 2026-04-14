#include <bits/stdc++.h>
using namespace std;

// Function to reverse a number
void reversenum(int n)
{
    int lastdigit;
    long long revnum = 0;

    // Extract digits and build reversed number
    while(n > 0)
    {
        lastdigit = n % 10;               // get last digit
        revnum = (revnum * 10) + lastdigit; // append digit
        n = n / 10;                      // remove last digit
    }

    cout << "The reverse of the number is: " << revnum;
}

int main()
{
    int n;
    cin >> n;
    reversenum(n);
    return 0;
}