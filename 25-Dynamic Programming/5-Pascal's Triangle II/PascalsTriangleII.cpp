// https://leetcode.com/problems/pascals-triangle-ii/description/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector with (rowIndex + 1) elements all set to 0
        vector<int> row(rowIndex + 1, 0);
        
        // The first element in every row of Pascal's Triangle is always 1
        row[0] = 1; 

        // Loop to build the row up to the desired rowIndex
        for (int i = 1; i <= rowIndex; i++) 
        {
            // Update the row in reverse to avoid overwriting the values
            // needed to compute the current value
            for (int j = i; j > 0; j--) 
            {
                // Each value is the sum of the two values above it in the triangle
                row[j] = row[j] + row[j - 1];
            }
        }

        // Return the final computed row
        return row;
    }
};
