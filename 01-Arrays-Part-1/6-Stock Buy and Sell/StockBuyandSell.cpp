// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;  // Variable to store the maximum profit
        int bestBuy = prices[0];  // Initialize the best buying price as the first day's price

        // Iterate through the prices starting from the second day
        for(int i = 1; i < prices.size(); i++) {
            // If the current price is greater than the best buying price,
            // calculate the profit and update maxProfit if the current profit is higher
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            // Update bestBuy to the minimum price seen so far
            bestBuy = min(bestBuy, prices[i]);
        }

        // Return the maximum profit calculated
        return maxProfit;
    }
};
