// https://leetcode.com/problems/palindrome-partitioning-ii/description/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // 2D table to store whether s[i..j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // dp[i] will hold the minimum number of cuts needed for s[0..i]
        vector<int> dp(n, 0);

        // Step 1: Precompute all palindromic substrings
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                // s[j..i] is a palindrome if:
                // characters at j and i are the same AND
                // the inner substring s[j+1..i-1] is a palindrome
                // OR the length is <= 2 (like "aa" or "aba")
                if (s[j] == s[i] && (i - j <= 2 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                }
            }
        }

        // Step 2: Compute minimum cuts using the palindrome table
        for (int i = 0; i < n; i++) {
            // If the whole substring s[0..i] is a palindrome, no cut is needed
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                // Initialize with maximum possible cuts (i cuts for i+1 characters)
                dp[i] = i;

                // Try cutting at every position j < i
                for (int j = 0; j < i; j++) {
                    // If s[j+1..i] is a palindrome,
                    // then the cut can be made after j
                    if (isPalindrome[j + 1][i]) {
                        // Update dp[i] with the minimum cut count
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        // The answer is the minimum number of cuts needed for s[0..n-1]
        return dp[n - 1];
    }
};
