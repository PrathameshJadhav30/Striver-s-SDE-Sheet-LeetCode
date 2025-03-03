// https://leetcode.com/problems/sqrtx/description
class Solution {
    public:
        int mySqrt(int x) {
            // If x is 0 or 1, return x itself (as sqrt(0) = 0 and sqrt(1) = 1)
            if (x == 0 || x == 1) {
                return x; 
            } 
                
            // Initialize binary search boundaries
            int left = 1, right = x, ans = 0;
            
            while (left <= right) {
                // Find the middle element to avoid integer overflow
                long long mid = left + (right - left) / 2;
                
                // If mid^2 equals x, return mid (perfect square case)
                if (mid * mid == x) {
                    return mid; 
                }     
                // If mid^2 is less than x, move search range to the right
                // and store mid as a potential answer (floor value)
                else if (mid * mid < x) {
                    ans = mid; 
                    left = mid + 1;
                } 
                // If mid^2 is greater than x, move search range to the left
                else {
                    right = mid - 1;
                }
            }
            
            // Return the largest integer whose square is ≤ x
            return ans; 
        }
    };
    