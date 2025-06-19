// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the start and end positions (0 and n) to the cuts array for easier interval handling
        cuts.push_back(0);
        cuts.push_back(n);
        
        // Sort the cuts so we can process the intervals in order
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();  // Total number of positions including 0 and n

        // Initialize a 2D DP array where dp[i][j] will store the minimum cost to cut stick from cuts[i] to cuts[j]
        vector<vector<int>> dp(c, vector<int>(c, 0));

        // Process all possible interval lengths starting from 2 (at least one cut in between)
        for (int length = 2; length < c; length++) 
        {
            // For each starting index i of the interval
            for (int i = 0; i + length < c; i++) 
            {
                int j = i + length; // Ending index of interval
                dp[i][j] = INT_MAX; // Initialize to a large value

                // Try all possible positions k for the first cut between i and j
                for (int k = i + 1; k < j; k++) 
                {
                    // Cost = current segment length + cost to cut left subinterval + cost to cut right subinterval
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];

                    // Store the minimum cost for this interval
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        // Return the minimum cost to cut the entire stick from position 0 to n
        return dp[0][c - 1];
    }
};
