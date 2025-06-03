// https://leetcode.com/problems/maximum-weighted-k-edge-path/description/
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // Step 1: Build adjacency list from the edge list
        // Each entry adj[u] contains pairs {v, wt} representing an edge u -> v with weight wt
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : edges){
             adj[e[0]].push_back({e[1], e[2]});
        }

        // Step 2: Initialize DP table
        // dp[u][e] = set of all possible path weights to reach node u using exactly e edges
        vector<vector<set<int>>> dp(n, vector<set<int>>(k + 1));

        // Step 3: Base case - weight 0 to reach any node with 0 edges (trivially true)
        for(int u = 0; u < n; u++){
           dp[u][0].insert(0);
        } 

        // Step 4: Fill DP table for 1 to k edges
        for(int e = 0; e < k; e++) // For each edge count from 0 to k-1
        {
            for(int u = 0; u < n; u++) // For each node u
            {
                for(auto& [v, wt] : adj[u]) // For each neighbor v of u with weight wt
                {
                    for(auto& w : dp[u][e]) // For each existing weight w to reach u in e edges
                    {
                        int new_w = w + wt; // Try extending to v
                        if(new_w < t){ // Only consider it if total weight is strictly less than t
                            dp[v][e + 1].insert(new_w); // Add to dp[v][e+1]
                        }
                    }
                }
            }
        }

        // Step 5: Find the maximum weight among all nodes using exactly k edges
        int ans = -1;
        for(int u = 0; u < n; u++)
        {
            if(!dp[u][k].empty()){
              // prev(dp[u][k].end()) gives iterator to the largest value in the set
              ans = max(ans, *prev(dp[u][k].end()));
            } 
        }

        return ans; // Return the maximum valid weight or -1 if none found
    }
};
