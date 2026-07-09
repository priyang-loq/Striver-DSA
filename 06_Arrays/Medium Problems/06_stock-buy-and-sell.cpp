#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum profit from a single buy and sell transaction
int stockbuySell(vector<int> &prices)
{
    // If the array is empty, no transaction is possible
    if (prices.empty())
        return 0;

    // Store the minimum stock price encountered so far
    int minPrice = prices[0];

    // Store the maximum profit found so far
    int maxProfit = 0;

    // Traverse the price array starting from the second day
    for (int i = 1; i < prices.size(); i++)
    {
        // Update the minimum buying price
        minPrice = min(minPrice, prices[i]);

        // Calculate profit if the stock is sold today
        int profit = prices[i] - minPrice;

        // Update the maximum profit
        maxProfit = max(maxProfit, profit);
    }

    // Return the maximum profit
    return maxProfit;
}

int main()
{
    // Stock prices for each day
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Print the maximum profit
    cout << stockbuySell(prices) << endl;

    return 0;
}