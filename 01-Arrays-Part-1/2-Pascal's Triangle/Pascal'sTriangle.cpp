// https://leetcode.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> pascalTriangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            // Resize the current row to have i+1 elements
            pascalTriangle[i].resize(i + 1);
            // The first and last elements of each row are always 1
            pascalTriangle[i][0] = 1;
            pascalTriangle[i][i] = 1;

            // Fill the middle elements of the row
            for (int j = 1; j < i; ++j) {
                pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }
        }

        return pascalTriangle;
    } 
    
};