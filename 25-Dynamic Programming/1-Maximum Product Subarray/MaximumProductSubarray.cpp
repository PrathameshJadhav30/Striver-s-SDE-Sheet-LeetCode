// https://leetcode.com/problems/maximum-product-subarray/description/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize maxProduct, currMax, and currMin with the first element
        int maxProduct = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        // Traverse the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If current number is negative, swap currMax and currMin
            // because multiplying by a negative makes max <-> min
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            // Update currMax and currMin
            // Either start a new subarray at nums[i] or continue the previous one
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            // Update the global maxProduct
            maxProduct = max(maxProduct, currMax);
        }

        return maxProduct;
    }
};
