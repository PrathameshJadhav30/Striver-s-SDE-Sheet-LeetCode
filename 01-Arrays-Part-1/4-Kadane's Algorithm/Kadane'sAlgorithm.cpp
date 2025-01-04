//https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize variables
        int currsum = 0; // Tracks the current subarray sum
        int maxsum = INT_MIN; // Stores the maximum subarray sum found so far

        // Iterate through the array using a normal for loop
        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i]; // Add the current element to the current subarray sum
            maxsum = max(currsum, maxsum); // Update the maximum sum if the current sum is greater
            
            // If the current sum becomes negative, reset it to 0
            if (currsum < 0) {
                currsum = 0;
            }
        }
        
        // Return the maximum subarray sum found
        return maxsum;
    }
};
