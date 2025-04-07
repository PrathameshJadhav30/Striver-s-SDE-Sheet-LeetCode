// https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            // If the input vector is empty, there is no common prefix
            if (strs.empty()) {
                return "";
            } 
    
            // Loop through each character of the first string
            for (int i = 0; i < strs[0].size(); i++) {
                char ch = strs[0][i];  // Get the i-th character of the first string
    
                // Compare this character with the same position in the other strings
                for (int j = 1; j < strs.size(); j++) {
                    // If i exceeds the current string's length OR characters mismatch
                    if (i >= strs[j].size() || strs[j][i] != ch) {
                        // Return the substring from index 0 to i (not including i)
                        return strs[0].substr(0, i);
                    }
                }
            }
    
            // If the loop completes, the entire first string is the common prefix
            return strs[0];
        }
    };
    