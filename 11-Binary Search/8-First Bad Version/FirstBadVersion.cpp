// https://leetcode.com/problems/first-bad-version/description
class Solution {
    public:
        int firstBadVersion(int n) {
            int left = 1, right = n;  // Initialize search boundaries
            
            while (left < right) {  // Binary search loop
                int mid = left + (right - left) / 2;  // Calculate mid to avoid integer overflow
                
                if (isBadVersion(mid)) {  
                    // If mid is a bad version, the first bad version must be at mid or before it
                    right = mid;  
                } else {  
                    // If mid is a good version, the first bad version must be after mid
                    left = mid + 1;  
                }
            }
            
            return left;  // Left will point to the first bad version
        }
    };
    