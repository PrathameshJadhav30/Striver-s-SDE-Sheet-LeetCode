// https://leetcode.com/problems/subsets-ii/description/
class Solution {
    public:
        // Helper function to generate all unique subsets
        void AllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
            // Base case: if we have processed all elements, add the subset to the result
            if (i == nums.size()) {
                allSubsets.push_back(ans);
                return;
            }
    
            // Include the current element in the subset
            ans.push_back(nums[i]);
            AllSubsets(nums, ans, i + 1, allSubsets);
            ans.pop_back(); // Backtrack to remove the last added element
    
            // Skip duplicate elements to avoid duplicate subsets
            int idx = i + 1;
            while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
                idx++;
            }
    
            // Exclude the current element and move to the next non-duplicate element
            AllSubsets(nums, ans, idx, allSubsets);
        }
    
        // Main function to return all unique subsets
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            // Sort the input array to handle duplicates efficiently
            sort(nums.begin(), nums.end());
    
            vector<vector<int>> allSubsets; // Stores all unique subsets
            vector<int> ans; // Temporary subset storage
            AllSubsets(nums, ans, 0, allSubsets);
            return allSubsets;
        }
    };
    