// https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
    
            // Edge case: empty string
            if (n == 0) {
                return "";
            }
    
            // Variables to store starting index and maximum length of the longest palindrome found
            int start = 0, maxLen = 1;
    
            // Loop through each character in the string
            for (int i = 0; i < n; i++) {
                // ---------- Check for Odd-Length Palindromes ----------
                // Set left and right pointers to the current character
                int l = i, r = i;
    
                // Expand while characters match and within bounds
                while (l >= 0 && r < n && s[l] == s[r]) {
                    // Update longest palindrome info if the new one is longer
                    if (r - l + 1 > maxLen) {
                        start = l;
                        maxLen = r - l + 1;
                    }
                    l--;  // Expand to the left
                    r++;  // Expand to the right
                }
    
                // ---------- Check for Even-Length Palindromes ----------
                // Set left to current and right to next character
                l = i, r = i + 1;
    
                // Expand while characters match and within bounds
                while (l >= 0 && r < n && s[l] == s[r]) {
                    // Update longest palindrome info if the new one is longer
                    if (r - l + 1 > maxLen) {
                        start = l;
                        maxLen = r - l + 1;
                    }
                    l--;  // Expand to the left
                    r++;  // Expand to the right
                }
            }
    
            // Return the longest palindromic substring found
            return s.substr(start, maxLen);
        }
    };
    