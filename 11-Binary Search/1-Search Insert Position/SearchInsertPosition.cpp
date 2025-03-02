// https://leetcode.com/problems/search-insert-position/description
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1; // Initialize left and right pointers
            
            while (left <= right) { // Continue until search space is exhausted
                int mid = left + (right - left) / 2; // Calculate the middle index (avoiding overflow)
                
                if (nums[mid] == target) { // If target is found at mid, return mid
                    return mid;
                } 
                else if (nums[mid] < target) { // If target is greater, search the right half
                   left = mid + 1;
                }    
                else { // If target is smaller, search the left half
                  right = mid - 1;
                }
            }
            
            // If target is not found, 'left' will be the correct insertion index
            return left; 
        }
    };
    