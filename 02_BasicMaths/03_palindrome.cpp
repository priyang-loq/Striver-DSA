#include <bits/stdc++.h>
using namespace std;

// Function to check palindrome
void palindromenum(int n)
{
    int lastdigit;
    long long revnum = 0;
    long long check = n; // store original

    while(n > 0)
    {
        lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }

    // Compare original and reversed
    if(check == revnum)
        cout << "The above number is Palindrome";
    else
        cout << "The above number is not Palindrome";
}

int main()
{
    int n;
    cin >> n;
    palindromenum(n);
    return 0;
}