// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/
class Solution {
    public:
        int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
            int n = capacity.size();  // Number of bags
    
            // Create a vector to store the number of rocks required to fill each bag to its capacity
            vector<int> required(n, 0);
    
            // Calculate the number of rocks required for each bag
            for (int i = 0; i < n; i++) {
                int currently_rock = rocks[i];       // Current number of rocks in the bag
                int capacity_rock = capacity[i];     // Capacity of the bag
    
                int require_rock = capacity_rock - currently_rock;  // Rocks needed to fill the bag
                required[i] = require_rock;  // Store the result in the required vector
            }
    
            // Sort the required vector to prioritize bags that need fewer rocks
            sort(begin(required), end(required));
    
            int count = 0;  // Counter for the number of bags that can be completely filled
    
            // Iterate through the sorted required vector
            for (int i = 0; i < n; i++) {
                if (required[i] == 0) {
                    // Bag is already full, increment the count
                    count++;
                } else {
                    // Check if there are enough additional rocks to fill the current bag
                    if (additionalRocks >= required[i]) {
                        additionalRocks -= required[i];  // Use the required number of rocks
                        count++;  // Increment the count of completely filled bags
                    } else {
                        // Not enough rocks to fill the current bag, stop the loop
                        break;
                    }
                }
            }
    
            return count;  // Return the total number of completely filled bags
        }
    };
    