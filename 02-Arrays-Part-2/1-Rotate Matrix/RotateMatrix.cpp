// https://leetcode.com/problems/rotate-image/description/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < (n + 1) / 2; ++i) { // Outer loop for layers
            for (int j = 0; j < n / 2; ++j) {  // Inner loop for elements in a layer
                // Start 4-way swaps
                int temp = matrix[n - 1 - j][i]; // bottom-left element
                
                // bottom-left = bottom-right
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                
                // bottom-right = top-right
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                
                // top-right = top-left
                matrix[j][n - 1 - i] = matrix[i][j];
                
                // top-left = temp (saved bottom-left)
                matrix[i][j] = temp;
            }
        }
    }
};
