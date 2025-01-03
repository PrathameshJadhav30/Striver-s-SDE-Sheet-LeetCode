class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first decreasing element from the end
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If i is still >= 0, find the next larger element and swap
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap elements at i and j
            swap(nums[i], nums[j]);
        }
        
        // Reverse the elements after index i
        reverse(nums.begin() + i + 1, nums.end());
    }
};