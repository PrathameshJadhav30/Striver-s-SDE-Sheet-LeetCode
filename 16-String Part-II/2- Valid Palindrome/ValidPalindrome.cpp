// https://leetcode.com/problems/valid-palindrome/description
class Solution {
    public:
        bool isPalindrome(string s) {
            // Initialize two pointers: one at the beginning and one at the end
            int left = 0, right = s.length() - 1;
    
            // Loop until the two pointers meet
            while (left < right) {
                
                // Move left pointer to the right if current character is not alphanumeric
                while (left < right && !isalnum(s[left])) {
                    left++;
                }
                
                // Move right pointer to the left if current character is not alphanumeric
                while (left < right && !isalnum(s[right])) {
                    right--;
                }
    
                // Compare the characters after converting them to lowercase
                if (tolower(s[left]) != tolower(s[right])) {
                    // If they don't match, it's not a palindrome
                    return false;
                }
    
                // Move both pointers closer to the center
                left++;
                right--;
            }
    
            // If all characters matched, it's a palindrome
            return true;
        }
    };
    