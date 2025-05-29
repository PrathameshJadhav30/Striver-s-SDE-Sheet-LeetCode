// https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Step 1: Build the adjacency list for all gardens (1-based indexing)
        // Each garden i has a list of connected gardens (neighbors)
        vector<vector<int>> adj(n + 1); // Using n+1 because gardens are numbered from 1 to n

        for (const auto& path : paths) 
        {
            // Add both directions since the paths are bidirectional
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }

        // Step 2: Initialize the result vector where res[i] = flower type for garden (i+1)
        // Initially all gardens have flower type 0 (unassigned)
        vector<int> res(n, 0);

        // Step 3: Assign flower type to each garden
        for (int i = 1; i <= n; i++) 
        {
            // Boolean array to track which flower types are used by adjacent gardens
            // Index 1 to 4 represent flower types (used[0] is unused)
            bool used[5] = {false};  

            // Check all neighbors of garden i
            for (int neighbor : adj[i]) 
            {
                if (res[neighbor - 1] != 0) // If neighbor already has a flower
                {
                    used[res[neighbor - 1]] = true; // Mark that flower type as used
                }
            }

            // Assign the first available flower type not used by neighbors
            for (int flower = 1; flower <= 4; flower++) 
            {
                if (!used[flower]) // Found an unused flower type
                {
                    res[i - 1] = flower; // Assign it to garden i (note: i - 1 for 0-based index)
                    break; // Move to the next garden
                }
            }
        }

        // Step 4: Return the result vector with flower types for each garden
        return res;
    }
};
