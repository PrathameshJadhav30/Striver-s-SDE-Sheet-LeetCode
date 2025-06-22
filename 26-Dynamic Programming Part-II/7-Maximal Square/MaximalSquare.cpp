// https://leetcode.com/problems/maximal-square/description/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();        // Number of rows in the matrix
        int n = matrix[0].size();     // Number of columns in the matrix
        int maxLen = 0;               // To store the side length of the largest square found
        
        // Create a 2D DP table initialized to 0
        // dp[i][j] will store the size of the largest square ending at (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                // Only process if the current cell has '1'
                if (matrix[i][j] == '1') 
                {
                    // If it's the first row or first column,
                    // the maximum square ending here is of size 1
                    if (i == 0 || j == 0) 
                    {
                        dp[i][j] = 1;
                    } 
                    else 
                    {
                        // Use the recurrence relation:
                        // Check top, left, and top-left diagonal cells
                        // Take their minimum and add 1
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    
                    // Update maxLen if we found a larger square
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        
        // Return the area of the largest square found
        return maxLen * maxLen;
    }
};
