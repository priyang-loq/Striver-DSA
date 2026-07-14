#include <bits/stdc++.h>
using namespace std;
int longSubArray(vector<int> &arr)
{
    int n = arr.size();
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                int length = j - i + 1;
                maxLength = max(maxLength, length);
            }
        }
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    cout << "The longest subarray is: " << longSubArray(arr);
    return 0;
}