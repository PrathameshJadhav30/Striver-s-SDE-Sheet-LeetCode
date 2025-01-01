// https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool isRowZero = false, isColZero = false;

        // Check if the first row has a zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                isRowZero = true;
                break;
            }
        }

        // Check if the first column has a zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isColZero = true;
                break;
            }
        }

        // Mark zeros in the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on markers in the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row
        if (isRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle the first column
        if (isColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
