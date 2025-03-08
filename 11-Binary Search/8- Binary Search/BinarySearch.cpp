// https://leetcode.com/problems/binary-search/description
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;  // Initialize two pointers
            
            while (left <= right) {  // Binary search loop
                int mid = left + (right - left) / 2;  // Calculate middle index (avoids overflow)
                
                if (nums[mid] == target) {  
                    return mid;  // Target found, return its index
                } 
                else if (nums[mid] < target) {  
                    left = mid + 1;  // Search in the right half
                } 
                else {  
                    right = mid - 1;  // Search in the left half
                }
            }
            
            return -1;  // Target not found, return -1
        }
    };
    