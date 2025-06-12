// https://leetcode.com/problems/edit-distance/description/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create a 2D DP table of size (m+1) x (n+1)
        // dp[i][j] represents the minimum edit distance to convert
        // first i characters of word1 to first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: converting word1[0...i] to empty word2 (i deletions)
        for (int i = 0; i <= m; i++) 
        {
            dp[i][0] = i;  // delete all characters from word1
        }

        // Base case: converting empty word1 to word2[0...j] (j insertions)
        for (int j = 0; j <= n; j++) 
        {
            dp[0][j] = j;  // insert all characters into word1
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                // If current characters match, no new operation needed
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    // If characters don't match, consider:
                    // 1. Deletion (dp[i-1][j])
                    // 2. Insertion (dp[i][j-1])
                    // 3. Replacement (dp[i-1][j-1])
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // Delete from word1
                        dp[i][j - 1],    // Insert into word1
                        dp[i - 1][j - 1] // Replace character in word1
                    });
                }
            }
        }

        // Final answer is the minimum operations to convert entire word1 to word2
        return dp[m][n];
    }
};
