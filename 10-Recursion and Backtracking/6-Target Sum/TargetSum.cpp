// https://leetcode.com/problems/target-sum/description
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;

        // Calculate the total sum of all elements in the nums array
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }

        // Check if it's possible to partition the array into two subsets
        // to achieve the given target sum
        if ((total_sum + target) % 2 != 0 || abs(target) > total_sum) {
            return 0; // If it's not possible, return 0
        }

        // Compute the required subset sum P
        int P = (total_sum + target) / 2;  

        // Initialize a DP array of size P + 1 to store the number of ways to achieve each sum
        vector<int> dp(P + 1, 0);
        dp[0] = 1;  // There is one way to form sum 0 (by choosing nothing)

        // Iterate through the nums array
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];  // Current number
            vector<int> new_dp = dp;  // Create a copy of the current dp array

            // Update new_dp using a normal for loop
            for (int j = num; j <= P; j++) {  
                new_dp[j] += dp[j - num];  // Add ways from previous dp state
            }

            dp = new_dp;  // Update dp with the new calculated values
        }

        return dp[P];  // The final answer is stored in dp[P], which is the number of ways to form the required sum
    }
};