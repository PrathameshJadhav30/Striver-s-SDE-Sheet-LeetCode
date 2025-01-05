// https://leetcode.com/problems/sort-colors/description/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();
        
        // Initialize three pointers:
        // low - to track the position for placing 0s
        // mid - to traverse the array
        // high - to track the position for placing 2s
        int low = 0, mid = 0, high = n - 1;

        // Loop until mid crosses high
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Case 1: Current element is 0
                // Swap it with the element at the 'low' pointer
                // Increment both 'low' and 'mid' pointers
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Case 2: Current element is 1
                // Leave it as is and move the 'mid' pointer
                mid++;
            } else {
                // Case 3: Current element is 2
                // Swap it with the element at the 'high' pointer
                // Decrement the 'high' pointer (do not increment 'mid' here
                // because the swapped element at 'mid' needs to be checked)
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
