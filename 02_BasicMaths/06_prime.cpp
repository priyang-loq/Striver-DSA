#include <bits/stdc++.h>
using namespace std;

// Function to check prime number
void prime(int n)
{
    int count = 0;
    int num = n;

    // Count divisors
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            count++;

            if(i != n / i)
            {
                count++;
            }
        }
    }

    // Prime condition: exactly 2 divisors
    if(count == 2)
    {
        cout << "The number: " << num << " is PRIME";
    }
    else
    {
        cout << "The number: " << num << " is not PRIME";
    }
}

int main()
{
    int n;
    cin >> n;
    prime(n);
    return 0;
}