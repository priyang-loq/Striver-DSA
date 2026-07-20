#include <bits/stdc++.h>
using namespace std;

// Class to handle bouquet formation logic
class RoseGarden {
public:
    // Function to check if we can form 'm' bouquets by 'day'
    bool isPossible(vector<int>& bloomDays, int day, int m, int k) {
        int count = 0;  // consecutive flowers that bloomed by 'day'
        int bouquets = 0;

        for (int bloom : bloomDays) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    // Main function to find the minimum day to form 'm' bouquets
    int minDaysToMakeBouquets(vector<int>& bloomDays, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        if (totalFlowers > bloomDays.size()) return -1; // Not enough flowers

        int low = *min_element(bloomDays.begin(), bloomDays.end());
        int high = *max_element(bloomDays.begin(), bloomDays.end());

        // Brute-force search from min to max bloom day
        for (int day = low; day <= high; ++day) {
            if (isPossible(bloomDays, day, m, k)) {
                return day;
            }
        }

        return -1; // Not possible to make bouquets
    }
};

int main() {
    vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;

    RoseGarden garden;
    int result = garden.minDaysToMakeBouquets(bloomDays, m, k);

    if (result == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << result << "\n";

    return 0;
}
