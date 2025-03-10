// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // Variables to store the two largest numbers
            int max1 = 0, max2 = 0;
            
            // Iterate through the array to find the two largest numbers
            for (int i = 0; i < nums.size(); i++) 
            {
                // If the current number is greater than max1, update max1 and shift max1 to max2
                if (nums[i] > max1) 
                {
                    max2 = max1;  // Assign previous max1 value to max2
                    max1 = nums[i];  // Update max1 with the new largest value
                } 
                // If the current number is not greater than max1 but greater than max2, update max2
                else if (nums[i] > max2) 
                {
                    max2 = nums[i];  // Update max2 with the second largest value
                }
            }
            
            // Compute and return the maximum product
            return (max1 - 1) * (max2 - 1);
        }
    };
    