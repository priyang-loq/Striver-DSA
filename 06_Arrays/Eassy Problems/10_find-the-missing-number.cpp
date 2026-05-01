#include <iostream>
#include <vector>
using namespace std;

// function to find missing number
int missingNum(vector<int> &arr)
{
    // total numbers should be size + 1
    int n = arr.size() + 1;

    // check from 1 to n
    for (int i = 1; i <= n; i++)
    {
        bool found = false; // assume number not found

        // search i in array
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }

        // if not found, return missing number
        if (found == false)
        {
            return i;
        }
    }

    return -1; // safety
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