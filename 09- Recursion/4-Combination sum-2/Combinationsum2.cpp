// https://leetcode.com/problems/combination-sum-ii/description/
class Solution {
    public:
        // Recursive function to find unique combinations that sum to the target
        void solve(vector<int>& arr, int target, int idx, vector<int>& curr, vector<vector<int>>& result) {
            // Base case: If target becomes negative, stop recursion
            if (target < 0) {
                return;
            }
            
            // Base case: If target becomes 0, store the current combination
            if (target == 0) {
                result.push_back(curr);
                return;
            }
    
            // Iterate through the array, starting from the given index
            for (int i = idx; i < arr.size(); i++) 
            {
                // Skip duplicate elements to avoid duplicate combinations
                if (i > idx && arr[i] == arr[i - 1]) 
                { 
                    continue;
                }
                
                // Choose the current element
                curr.push_back(arr[i]); // Do
                
                // Recursively explore with reduced target and move to the next index (i+1)
                solve(arr, target - arr[i], i + 1, curr, result); // Explore
                
                // Backtrack: Remove the last chosen element before moving to the next iteration
                curr.pop_back(); // Undo
            }
        }
    
        // Main function to find all unique combinations
        vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
            vector<vector<int>> result; // Stores all unique combinations
            vector<int> curr; // Stores the current combination
    
            // Sort the array to handle duplicates efficiently and facilitate backtracking
            sort(arr.begin(), arr.end()); 
            
            // Start backtracking from index 0
            solve(arr, target, 0, curr, result); 
    
            return result;
        }
    };
    