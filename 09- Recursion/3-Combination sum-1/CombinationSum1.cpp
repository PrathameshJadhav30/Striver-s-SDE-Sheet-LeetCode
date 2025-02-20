// https://leetcode.com/problems/combination-sum/description/
class Solution {
    public:
        // Set to store unique combinations
        set<vector<int>> s;
    
        // Recursive function to find all possible combinations
        void getAllCombination(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
            // Base case: If target is 0, we found a valid combination
            if (tar == 0) {
                // Ensure the combination is unique before adding to result
                if (s.find(combin) == s.end()) {
                    ans.push_back(combin);
                    s.insert(combin);
                }
                return;
            }
    
            // Base case: If index exceeds array size or target becomes negative, return
            if (idx == arr.size() || tar < 0) {
                return;
            }
    
            // Include the current element (single occurrence)
            combin.push_back(arr[idx]);
            getAllCombination(arr, idx + 1, tar - arr[idx], ans, combin);
    
            // Include the current element (multiple occurrences)
            getAllCombination(arr, idx, tar - arr[idx], ans, combin);
    
            // Backtracking step: Remove the last added element
            combin.pop_back();
    
            // Exclude the current element and move to the next index
            getAllCombination(arr, idx + 1, tar, ans, combin);
        }
    
        // Main function to find all unique combinations that sum up to target
        vector<vector<int>> combinationSum(vector<int>& arr, int target) {
            vector<vector<int>> ans;  // Stores the final list of valid combinations
            vector<int> combin;       // Temporary list to store the current combination
    
            getAllCombination(arr, 0, target, ans, combin);  // Start recursion
    
            return ans;
        }
    };
    