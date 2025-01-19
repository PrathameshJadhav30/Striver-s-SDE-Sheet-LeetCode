// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        // Create an unordered_map to store the elements and their indices
        unordered_map<int, int> m;
        // Vector to store the result
        vector<int> ans;

        // Loop through the array
        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];           // Current element
            int sec = tar - first;        // The number needed to reach the target

            // Check if the required number (sec) exists in the map
            if(m.find(sec) != m.end()) {
                ans.push_back(i);         // Add the current index to the result
                ans.push_back(m[sec]);    // Add the index of the required number
                break;                    // Break the loop as the solution is found
            }

            // Store the current element with its index in the map
            m[first] = i;
        }

        // Return the indices of the two numbers that add up to the target
        return ans;
    }
};
