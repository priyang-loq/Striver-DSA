#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100];   // array to store elements
    int n;

    // Taking number of elements as input
    cout << "Enter the number of elements of the array: ";
    cin >> n;

    // Taking array elements as input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];   // storing elements in array
    }

    int hss[100] = {0};   // hash array to store frequency (initialized with 0)

    // Storing frequency of each element
    // hss[x] will store how many times x appears
    for (int i = 0; i < n; i++)
    {
        hss[arr[i]]++;   // increment frequency of element
    }

    int q;

    // Taking number of queries
    cout << "\nEnter number of queries: ";
    cin >> q;

    int query[100];   // array to store query elements

    // Taking query elements as input
    cout << "Enter the query elements: ";
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }

    cout << "\n--- Results ---\n";

    // Processing each query
    for (int i = 0; i < q; i++)
    {
        // Printing frequency of each queried element
        cout << "Frequency of " << query[i] << " is: " 
             << hss[query[i]] << endl;
    }

    return 0;   // program ends successfully
}