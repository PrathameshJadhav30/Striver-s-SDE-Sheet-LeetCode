// https://leetcode.com/problems/max-consecutive-ones/description/
class Solution {
    public:
        // Function to find the maximum number of consecutive 1s in a binary array
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;       // To track the current count of consecutive 1s
            int max_count = 0;   // To store the maximum count of consecutive 1s found so far
    
            // Iterate through each element in the array
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {  // If the current element is 1
                    count++;         // Increment the current count
                    max_count = max(max_count, count);  // Update max_count if the current count is larger
                } else {  // If the current element is 0
                    count = 0;  // Reset the current count to 0
                }
            }
    
            // Return the maximum count of consecutive 1s found
            return max_count;
        }
    };