// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size(); // Get the size of the input array
            int result = 0; // Initialize the result variable
    
            // Compute the bitwise OR of all elements in the array
            for(int i = 0; i < n; i++)  
            {
                result |= nums[i]; // Perform bitwise OR operation
            }
    
            // Multiply the OR result by 2^(n-1) (left shift is equivalent to multiplying by power of 2)
            return result << (n - 1);
        }
    };
    