// https://leetcode.com/problems/word-break/description/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Store all words from wordDict into an unordered_set for fast lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        // dp[i] will be true if s[0...i-1] can be segmented using words from the dictionary
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string can always be segmented

        // Iterate through the string from index 1 to n
        for (int i = 1; i <= n; i++) 
        {
            // Try every possible partition of the substring s[0...i-1]
            for (int j = 0; j < i; j++) 
            {
                // If the substring s[0...j-1] can be segmented (dp[j] is true)
                // and s[j...i-1] is a valid word in the dictionary
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true; // s[0...i-1] can be segmented
                    break; // No need to check further partitions for this i
                }
            }
        }

        // Return whether the full string can be segmented
        return dp[n]; 
    }
};
// Time Complexity: O(n^2 * m), where n is the length of the string s and m is the average length of words in wordDict
// Space Complexity: O(n), for the dp array and the unordered_set