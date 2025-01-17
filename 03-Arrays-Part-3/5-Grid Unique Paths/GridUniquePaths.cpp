// https://leetcode.com/problems/unique-paths/description/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D grid initialized with 0s
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Iterate over the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If we are at the first row or first column,
                // there is only one way to reach that cell (either all right moves or all down moves)
                if (i == 0 || j == 0)
                    grid[i][j] = 1;
                else
                    // The number of ways to reach this cell is the sum of the ways
                    // to reach the cell directly above and the cell to the left
                    grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }

        // Return the number of ways to reach the bottom-right corner
        return grid[m - 1][n - 1];
    }
};
