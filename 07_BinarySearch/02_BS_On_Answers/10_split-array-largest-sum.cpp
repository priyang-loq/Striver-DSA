#include <bits/stdc++.h>
using namespace std;

class SubarrayPartitioner
{
public:
    // Counts how many partitions are needed for a given maxSum
    int countPartitions(vector<int> &a, int maxSum)
    {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : a)
        {
            if (subarraySum + num <= maxSum)
            {
                subarraySum += num;
            }
            else
            {
                partitions++;
                subarraySum = num;
            }
        }

        return partitions;
    }

    // Finds the minimum largest subarray sum possible for at most k partitions
    int largestSubarraySumMinimized(vector<int> &a, int k)
    {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        // Binary search for the smallest maxSum
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int partitions = countPartitions(a, mid);

            if (partitions > k)
            {
                low = mid + 1; // Too many partitions
            }
            else
            {
                high = mid - 1; // Valid, try smaller maxSum
            }
        }

        return low;
    }
};

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;

    SubarrayPartitioner sp;

    int ans = sp.largestSubarraySumMinimized(a, k);

    cout << "The answer is: " << ans << endl;

    return 0;
}