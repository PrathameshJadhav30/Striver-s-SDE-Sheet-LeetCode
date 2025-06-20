// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;  // Initialize total profit to 0

        // Loop through the price array from the second day
        for (int i = 1; i < prices.size(); i++) 
        {
            // If today's price is greater than yesterday's, there is a profit opportunity
            if (prices[i] > prices[i - 1]) 
            {
                // Buy on the previous day and sell today
                // Add the difference to total profit
                profit += prices[i] - prices[i - 1];
            }
            // If not profitable, skip to next day
        }

        // Return the accumulated profit
        return profit;
    }
};
