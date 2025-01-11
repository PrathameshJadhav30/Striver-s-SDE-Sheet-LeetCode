// https://leetcode.com/problems/find-missing-and-repeated-values/description/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans; // Stores the repeated and missing values
        unordered_set<int> s; // Set to track unique numbers
        int n = grid.size(); // Size of the grid (n x n)
        int a, b; // Variables to store the repeated and missing values
        long long expSum = 0, actualSum = 0; // Use long long to handle larger values
        
        // Traverse the grid to calculate the actual sum and find the repeated value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j]; // Add the current number to the actual sum

                // Check if the number is already in the set
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j]; // Found the repeated number
                } else {
                    s.insert(grid[i][j]); // Add the number to the set
                }
            }
        }

        // Calculate the expected sum of numbers from 1 to n^2
        expSum = (long long)(n * n) * (n * n + 1) / 2;

        // Calculate the missing number using the formula
        b = expSum - (actualSum - a);

        // Add the repeated number (a) and the missing number (b) to the result
        ans.push_back(a);
        ans.push_back(b);

        return ans; // Return the result
    }
};
