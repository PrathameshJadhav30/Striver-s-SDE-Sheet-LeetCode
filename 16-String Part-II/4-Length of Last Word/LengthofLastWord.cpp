// https://leetcode.com/problems/length-of-last-word/description
class Solution {
    public:
        int lengthOfLastWord(string s) {
            int length = 0;                  // Variable to store the length of the last word
            int i = s.length() - 1;         // Start from the end of the string
    
            // Skip any trailing spaces at the end of the string
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
    
            // Count the length of the last word (until a space or start of string is found)
            while (i >= 0 && s[i] != ' ') {
                length++;
                i--;
            }
    
            return length;  // Return the final length of the last word
        }
    };
    