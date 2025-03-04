// https://leetcode.com/problems/valid-perfect-square/description
class Solution {
    public:
        bool isPerfectSquare(int num) {
            // Use binary search to check if `num` is a perfect square
            long long left = 1, right = num;
             
            while (left <= right) {
                // Calculate the middle value to check its square
                long long mid = left + (right - left) / 2;
                long long Square = mid * mid;
                
                // If mid squared is equal to num, then it's a perfect square
                if (Square == num) {
                    return true;
                }
                // If mid squared is less than num, search in the right half
                else if (Square < num) {
                    left = mid + 1;
                }
                // If mid squared is greater than num, search in the left half
                else {
                    right = mid - 1;
                }
            }
            
            // If no perfect square was found, return false
            return false;
        }
    };
    