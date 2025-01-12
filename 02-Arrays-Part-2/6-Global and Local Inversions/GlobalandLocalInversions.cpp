// https://leetcode.com/problems/global-and-local-inversions/description/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Check if the current element nums[i] is more than 1 position
            // away from its original sorted position (index i).
            // If |nums[i] - i| > 1, it indicates a global inversion that is not a local inversion.
            if (abs(nums[i] - i) > 1) {
                return false; // Not an ideal permutation
            }
        }
        
        // If no global inversion exists that is not a local inversion,
        // the permutation is ideal.
        return true;
    }
};
