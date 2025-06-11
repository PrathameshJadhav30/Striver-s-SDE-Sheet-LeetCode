// https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();  // Length of first string
        int n = text2.size();  // Length of second string

        // Create a 2D DP table initialized with 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If characters match, extend the subsequence
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                // Else take the max by excluding one character from either string
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The last cell contains the result
        return dp[m][n];
    }
};
