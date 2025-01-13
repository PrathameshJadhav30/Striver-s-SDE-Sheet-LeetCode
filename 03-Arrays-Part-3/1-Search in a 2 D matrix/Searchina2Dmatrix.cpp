class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows (m) and columns (n) in the matrix
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize pointers for binary search
        int left = 0;              // Start of the search range
        int right = m * n - 1;     // End of the search range (last index in the flattened matrix)
        
        // Perform binary search
        while (left <= right) {
            // Calculate the middle index to avoid overflow
            int mid = left + (right - left) / 2;
            
            // Map the 1D mid index to the 2D matrix value
            int midValue = matrix[mid / n][mid % n];
            
            // If the middle value equals the target, return true
            if (midValue == target) {
                return true; // Target found
            } 
            // If the middle value is less than the target, search in the right half
            else if (midValue < target) {
                left = mid + 1;
            } 
            // If the middle value is greater than the target, search in the left half
            else {
                right = mid - 1;
            }
        }
        
        // Target not found in the matrix
        return false;
    }
};
