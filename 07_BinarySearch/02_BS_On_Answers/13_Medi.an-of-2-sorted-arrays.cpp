#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high)
        {

            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1)
            {

                // Odd total number of elements
                if ((n1 + n2) % 2 == 1)
                {
                    return max(left1, left2);
                }

                // Even total number of elements
                else
                {
                    return (max(left1, left2) +
                            min(right1, right2)) /
                           2.0;
                }
            }

            // We have taken too many elements from nums1
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }

            // We have taken too few elements from nums1
            else
            {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution obj;

    double ans = obj.findMedianSortedArrays(nums1, nums2);

    cout << "The median is: " << ans << endl;

    return 0;
}