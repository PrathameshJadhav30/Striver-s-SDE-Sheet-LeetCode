// https://leetcode.com/problems/permutations-ii/description/
class Solution {
    public:
        // Helper function for backtracking to generate unique permutations
        void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
            // If the current permutation is complete, add it to the result list
            if (current.size() == nums.size()) 
            {
                result.push_back(current);
                return;
            }
    
            // Iterate through the numbers to construct permutations
            for (int i = 0; i < nums.size(); i++) {
                // Skip already used elements or duplicate elements to avoid duplicate permutations
                if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                    continue;
                }
                
                // Mark the element as used and add it to the current permutation
                used[i] = true;
                current.push_back(nums[i]);
                
                // Recursively call backtrack to fill the next position
                backtrack(nums, result, current, used);
                
                // Backtrack: Remove the last element and mark it as unused
                current.pop_back();
                used[i] = false;
            }
        }
        
        // Function to return all unique permutations of the given array
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> result;  // Stores all unique permutations
            vector<int> current;         // Stores the current permutation
            vector<bool> used(nums.size(), false); // Tracks whether an element is used
    
            // Sort the numbers to easily handle duplicates
            sort(nums.begin(), nums.end());
            
            // Start backtracking to generate permutations
            backtrack(nums, result, current, used);
    
            return result;  // Return the list of unique permutations
        }  
    };
    