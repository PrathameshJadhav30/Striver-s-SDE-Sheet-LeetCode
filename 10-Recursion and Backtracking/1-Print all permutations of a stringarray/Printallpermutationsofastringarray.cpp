// https://leetcode.com/problems/permutations/description/
class Solution {
    public:
        // Helper function to generate permutations using backtracking
        void getPerm(vector<int>& nums, int idx, vector<vector<int>>& ans) {
            // Base case: If index reaches the end of the array, store the permutation
            if (idx == nums.size()) {
                ans.push_back(nums); // Store the current permutation
                return;
            }
    
            // Iterate through all elements starting from idx
            for (int i = idx; i < nums.size(); i++) {
                swap(nums[idx], nums[i]); // Swap the current element with idx
                getPerm(nums, idx + 1, ans); // Recur for the next index
                swap(nums[idx], nums[i]); // Backtrack to restore the original order
            }
        }
    
        // Function to return all permutations of the given array
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans; // Store all permutations
            getPerm(nums, 0, ans); // Call helper function to generate permutations
            return ans; // Return the result
        }
    };
    