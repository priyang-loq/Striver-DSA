#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // Taking string input from user
    cout << "Enter the characters: ";
    cin >> s;

    int hss[256] = {0};   // hash array for all ASCII characters (0–255)

    // Storing frequency of each character in string
    // hss[c] will store how many times character 'c' appears
    for (int i = 0; i < s.size(); i++)
    {
        hss[s[i]]++;   // increment frequency using ASCII value as index
    }

    int q;

    // Taking number of queries
    cout << "\nEnter number of queries: ";
    cin >> q;

    char query[100];   // array to store query characters

    // Taking query characters as input
    cout << "Enter the query elements: ";
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }

    cout << "\n--- Results ---\n";

    // Processing each query
    for (int i = 0; i < q; i++)
    {
        // Printing frequency of each queried character
        cout << "Frequency of " << query[i] << " is: " 
             << hss[query[i]] << endl;
    }

    return 0;   // program ends successfully
}