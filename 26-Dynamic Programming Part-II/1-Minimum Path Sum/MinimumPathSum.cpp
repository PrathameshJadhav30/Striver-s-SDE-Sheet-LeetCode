// https://leetcode.com/problems/minimum-path-sum/description/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();        // Total number of rows in the grid
        int n = grid[0].size();     // Total number of columns in the grid

        // Traverse each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If we're not on the first row or first column,
                // add the minimum of the top or left cell to the current cell
                if (i > 0 && j > 0){
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }

                // If we're on the first column (can only come from the top)
                else if (i > 0){
                    grid[i][j] += grid[i-1][j];
                }   

                // If we're on the first row (can only come from the left)
                else if (j > 0){
                    grid[i][j] += grid[i][j-1];
                }   
            }
        }

        // Return the value in the bottom-right corner,
        // which now holds the minimum path sum from top-left to bottom-right
        return grid[m-1][n-1];
    }
};
