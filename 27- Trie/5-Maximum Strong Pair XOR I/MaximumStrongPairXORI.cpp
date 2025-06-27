// https://leetcode.com/problems/maximum-strong-pair-xor-i/description/
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxXor = 0;              // Variable to store the maximum XOR value found
        int n = nums.size();         // Size of the input array
        
        // Loop through all possible pairs of elements (including same elements)
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                int x = nums[i];
                int y = nums[j];
                
                // Check if (x, y) form a strong pair
                // A pair is strong if |x - y| <= min(x, y)
                if (abs(x - y) <= min(x, y))
                {
                    // If strong pair, calculate XOR and update maxXor if it's greater
                    maxXor = max(maxXor, x ^ y);
                }
            }
        }

        // Return the maximum XOR value found among all strong pairs
        return maxXor;
    }
};
