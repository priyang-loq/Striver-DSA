#include <bits/stdc++.h>
using namespace std;

// Function to print all divisors
void divisors(int n)
{
    vector<int> divisor;

    // Loop till sqrt(n)
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divisor.push_back(i);

            // Avoid duplicate divisor
            if(i != n / i)
            {
                divisor.push_back(n / i);
            }
        }
    }

    // Sort divisors
    sort(divisor.begin(), divisor.end());

    cout << "The divisors are: ";
    for(auto it = divisor.begin(); it != divisor.end(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    divisors(n);
    return 0;
}