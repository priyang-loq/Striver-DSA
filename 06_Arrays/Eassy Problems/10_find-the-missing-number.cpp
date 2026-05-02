#include <bits/stdc++.h>
using namespace std;

// function to find missing number
int missingNum(vector<int> &arr)
{
    int n = arr.size() + 1;
    long long  sum = 0;
    
    for (int i = 0 ; i < n-1; i++)
    {
        sum = sum + arr[i];
    }
    long long expSum = (n *1LL* (n + 1)) / 2;  
    return expSum - sum;

}

int main()
{
    int n;

    // input size (n-1 elements)
    cout << "Enter size of array (n-1): ";
    cin >> n;

    vector<int> arr(n);

    // input elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // function call
    int ans = missingNum(arr);

    // output result
    cout << "Missing number is: " << ans;

    return 0;
}