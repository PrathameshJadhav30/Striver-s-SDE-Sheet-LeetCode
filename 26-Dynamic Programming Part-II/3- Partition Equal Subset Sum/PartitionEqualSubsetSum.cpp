// https://leetcode.com/problems/partition-equal-subset-sum/description/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        // Step 1: Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: If the total sum is odd, it can't be partitioned into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        // Step 3: Set the target sum to half of total sum
        int target = totalSum / 2;
        int n = nums.size();

        // Step 4: Initialize DP array of size (target + 1)
        // dp[j] means whether it's possible to get sum 'j' using some elements from the array
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: 0 sum is always possible (by selecting no elements)

        // Step 5: Iterate through each number in the array
        for (int num : nums) {
            // Traverse the dp array from target down to current num
            // This ensures each number is only used once (0/1 knapsack approach)
            for (int j = target; j >= num; j--) {
                // Update dp[j] to true if dp[j] was already true
                // or if we can form sum j by adding current num to dp[j - num]
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // Step 6: If dp[target] is true, we can form a subset with sum equal to target
        return dp[target];
    }
};
