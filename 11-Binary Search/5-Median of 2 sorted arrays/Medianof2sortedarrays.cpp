// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
           
            // Ensure arr1 is the smaller array to optimize binary search
            if (arr1.size() > arr2.size()) {
                return findMedianSortedArrays(arr2, arr1);
            }
    
            int size1 = arr1.size();
            int size2 = arr2.size();
            int left = 0, right = size1;
    
            // Perform binary search on the smaller array
            while (left <= right) {
                int cut1 = (left + right) / 2;  // Partition index for arr1
                int cut2 = (size1 + size2 + 1) / 2 - cut1;  // Partition index for arr2
    
                int left1, right1, left2, right2;
    
                // Assign values for left1 and right1, handling edge cases
                if (cut1 == 0) {
                    left1 = INT_MIN;  // If cut1 is at the start, there is no left part
                } else {
                    left1 = arr1[cut1 - 1];
                }
    
                if (cut1 == size1) {
                    right1 = INT_MAX;  // If cut1 is at the end, there is no right part
                } else {
                    right1 = arr1[cut1];
                }
    
                // Assign values for left2 and right2, handling edge cases
                if (cut2 == 0) {
                    left2 = INT_MIN;
                } else {
                    left2 = arr2[cut2 - 1];
                }
    
                if (cut2 == size2) {
                    right2 = INT_MAX;
                } else {
                    right2 = arr2[cut2];
                }
    
                // Check if we found the correct partition
                if (left1 <= right2 && left2 <= right1) {
                    // If total size is even, return the average of the middle elements
                    if ((size1 + size2) % 2 == 0) {
                        return (max(left1, left2) + min(right1, right2)) / 2.0;
                    } else {
                        // If total size is odd, return the max of left partition
                        return max(left1, left2);
                    }
                } 
                // Adjust the binary search range
                else if (left1 > right2) {
                    right = cut1 - 1;  // Move towards the left in arr1
                } else {
                    left = cut1 + 1;  // Move towards the right in arr1
                }
            }
            return 0.0;  // This line will never be reached due to the problem constraints
        }
    };
    