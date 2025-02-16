// https://leetcode.com/problems/maximum-distance-in-arrays/description/
class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            // Initialize MIN and MAX with the first array's first and last elements
            int MIN = arrays[0].front();
            int MAX = arrays[0].back();
            int result = 0;
    
            // Iterate through the remaining arrays
            for (int i = 1; i < arrays.size(); i++) {
                int currMin = arrays[i].front(); // First element of current array
                int currMax = arrays[i].back();  // Last element of current array
    
                // Calculate the maximum absolute difference using previous MIN and MAX
                result = max({result, abs(currMin - MAX), abs(currMax - MIN)});
    
                // Update overall MIN and MAX values
                MAX = max(MAX, currMax);
                MIN = min(MIN, currMin);
            }
    
            return result;
        }
    };
    