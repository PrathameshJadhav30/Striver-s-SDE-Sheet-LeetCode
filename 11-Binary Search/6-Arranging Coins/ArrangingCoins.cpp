// https://leetcode.com/problems/arranging-coins/description
class Solution {
    public:
        int arrangeCoins(int n) {
            // Use long to prevent integer overflow when computing sum
            long left = 0, right = n, mid, sum;
            
            // Binary search to find the largest k such that k * (k + 1) / 2 <= n
            while (left <= right) {
                mid = left + (right - left) / 2;  // Avoid overflow when calculating mid
                sum = mid * (mid + 1) / 2;  // Sum of first 'mid' natural numbers
                
                if (sum == n) {
                    return mid;  // Exact match found, return mid as the answer
                }
                else if (sum < n) {
                    left = mid + 1;  // If sum is less, try to increase k
                }
                else {
                    right = mid - 1;  // If sum exceeds n, reduce k
                }
            }
            
            return right;  // Return the last valid k that fits in n
        }
    };
// Time Complexity: O(log(n))
// Space Complexity: O(1)    