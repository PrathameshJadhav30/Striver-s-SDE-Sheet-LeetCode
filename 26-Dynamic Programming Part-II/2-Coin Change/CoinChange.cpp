// https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array of size amount+1, initialized with a large value (amount+1),
        // since the minimum number of coins needed can't be more than amount.
        vector<int> dp(amount + 1, amount + 1);

        // Base case: To make amount 0, we need 0 coins.
        dp[0] = 0;

        // Iterate through all amounts from 1 to the target amount.
        for (int i = 1; i <= amount; i++) 
        {
            // Try using every coin for the current amount i
            for (int coin : coins) 
            {
                // If the coin can be used (i.e., coin <= current amount i)
                if (i - coin >= 0) 
                {
                    // Update dp[i] to the minimum coins needed
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still greater than amount, then it was not possible to form the amount
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
