// https://leetcode.com/problems/n-queens/description/
class Solution {
    public:
        // Function to check if placing a queen at board[row][col] is safe
        bool isSafe(vector<string> &board, int row, int col, int n) {
            // Check column for any queen placed above the current row
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') {
                    return false;
                }
            }
            
            // Check upper left diagonal for any queen
            for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }
            
            // Check upper right diagonal for any queen
            for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }
            
            return true; // If no conflicts, return true
        }
    
        // Function to solve N-Queens using backtracking
        void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans, vector<int>& columns, vector<int>& diag1, vector<int>& diag2) {
            // If all queens are placed successfully, add solution to answer list
            if (row == n) {
                ans.push_back(board);
                return;
            }
            
            // Try placing a queen in each column of the current row
            for (int j = 0; j < n; j++) {
                // Check if the column and diagonals are safe
                if (!isSafe(board, row, j, n) || columns[j] || diag1[row + j] || diag2[row - j + n - 1]) {
                    continue;
                }
                
                // Place the queen
                board[row][j] = 'Q';
                columns[j] = diag1[row + j] = diag2[row - j + n - 1] = 1;
                
                // Recur to place the rest of the queens
                nQueens(board, row + 1, n, ans, columns, diag1, diag2);
                
                // Backtrack: Remove the queen and reset tracking arrays
                board[row][j] = '.';
                columns[j] = diag1[row + j] = diag2[row - j + n - 1] = 0;
            }
        }
        
        // Main function to initialize board and call helper function
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans; // Store all possible solutions
            vector<string> board(n, string(n, '.')); // Initialize empty board
    
            // Vectors to track column and diagonal constraints
            vector<int> columns(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
    
            // Start placing queens from row 0
            nQueens(board, 0, n, ans, columns, diag1, diag2);
    
            return ans; // Return all valid solutions
        }
    };
    