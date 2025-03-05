// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1;  // Initialize left and right pointers
    
            while (l <= r) {  // Perform binary search
                int mid = l + (r - l) / 2;  // Calculate the middle index
    
                if (nums[mid] == target) {  // If target is found at mid, return index
                    return mid;
                }
    
                // Check if the left half is sorted
                if (nums[l] <= nums[mid]) {
                    // Check if target lies within the sorted left half
                    if (nums[l] <= target && target < nums[mid]) {
                        r = mid - 1;  // Move search range to left half
                    } else {
                        l = mid + 1;  // Move search range to right half
                    }
                }
                // Otherwise, the right half must be sorted
                else {
                    // Check if target lies within the sorted right half
                    if (nums[mid] < target && target <= nums[r]) {
                        l = mid + 1;  // Move search range to right half
                    } else {
                        r = mid - 1;  // Move search range to left half
                    }
                }
            }
            return -1;  // Target not found
        }
    };
    