// https://leetcode.com/problems/sudoku-solver/description/
class Solution {
    public:
        // Function to solve the Sudoku puzzle using backtracking
        bool solve(vector<vector<char>>& board) {
            // Traverse through the board
            for (int row = 0; row < 9; row++) {
                for (int col = 0; col < 9; col++) {
                    // Check if the current cell is empty ('.')
                    if (board[row][col] == '.') {
                        // Try placing numbers from '1' to '9'
                        for (char num = '1'; num <= '9'; num++) {
                            // Check if placing 'num' is valid
                            if (isValid(board, row, col, num)) {
                                board[row][col] = num; // Place the number
                                // Recursively attempt to solve the rest of the board
                                if (solve(board)) {
                                    return true; // If solved, return true
                                }
                                board[row][col] = '.'; // Backtrack if placing 'num' doesn't lead to a solution
                            }
                        }
                        return false; // No valid number found, backtrack
                    }
                }
            }
            return true; // Puzzle solved
        }
    
        // Function to check if placing 'num' at board[row][col] is valid
        bool isValid(vector<vector<char>>& board, int row, int col, char num) {
            for (int i = 0; i < 9; i++) {
                // Check if 'num' is already present in the same row
                if (board[row][i] == num) {
                    return false;
                }
                // Check if 'num' is already present in the same column
                if (board[i][col] == num) {
                    return false;
                }
                // Check if 'num' is already present in the 3x3 sub-box
                int subRow = (row / 3) * 3 + i / 3;
                int subCol = (col / 3) * 3 + i % 3;
                if (board[subRow][subCol] == num) {
                    return false;
                }
            }
            return true; // Placement is valid
        }
    
        // Public function to initiate Sudoku solving
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
    };