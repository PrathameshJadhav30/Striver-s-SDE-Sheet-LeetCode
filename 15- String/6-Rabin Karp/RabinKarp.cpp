// https://leetcode.com/problems/repeated-string-match/description/
class Solution {
    public:
        int repeatedStringMatch(string a, string b) {
            // Calculate the minimum number of times we need to repeat 'a' 
            // so that its total length is at least equal to the length of 'b'
            int repeat = (b.length() + a.length() - 1) / a.length();  
    
            string repeatedA = "";
    
            // Repeat 'a' the required number of times
            for (int i = 0; i < repeat; i++) {
                repeatedA += a;
            }
    
            // Check if 'b' is a substring of the repeated string
            if (repeatedA.find(b) != string::npos) {
                return repeat;
            }
    
            // Try repeating 'a' one more time in case 'b' spans across the boundary
            repeatedA += a;
    
            // Check again after one more repetition
            if (repeatedA.find(b) != string::npos) {
                return repeat + 1;
            }
    
            // If 'b' is not found in any of the repeated versions, return -1
            return -1;
        }
    };
    