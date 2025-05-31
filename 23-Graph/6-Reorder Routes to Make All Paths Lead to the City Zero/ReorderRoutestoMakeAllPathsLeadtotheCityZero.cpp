// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Adjacency list to represent the undirected graph
        vector<vector<int>> graph(n);

        // Set to store the original directed edges as (from -> to)
        set<pair<int, int>> directedEdges;
        
        // Build the graph and record the original direction of each edge
        for (auto& conn : connections) 
        {
            int from = conn[0], to = conn[1];

            // Add both directions to the graph for traversal
            graph[from].push_back(to);
            graph[to].push_back(from);

            // Record the original direction: from -> to
            directedEdges.insert({from, to}); 
        }

        int changes = 0; // Counter to track number of edges to be reversed
        vector<bool> visited(n, false); // Visited array to track DFS traversal

        // DFS function starting from a node
        function<void(int)> dfs = [&](int node) 
        {
            visited[node] = true; // Mark the current node as visited

            // Traverse all neighbors of the current node
            for (int neighbor : graph[node]) 
            {
                if (!visited[neighbor]) 
                {
                    // If the original edge is in the direction (node -> neighbor),
                    // it means it is away from city 0 and must be reversed
                    if (directedEdges.count({node, neighbor})) 
                    {
                        changes++; // Count this edge as needing a change
                    }

                    // Continue DFS traversal from the neighbor
                    dfs(neighbor);
                }
            }
        };

        dfs(0); // Start DFS from the capital city (node 0)
        return changes; // Return the total number of changes required
    }
};
