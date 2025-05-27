// https://leetcode.com/problems/all-paths-from-source-to-target/description/
class Solution {
public:
    // Main function to find all paths from node 0 to node n-1
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;  // Stores all valid paths
        vector<int> path;            // Temporary path to track current traversal

        // Start DFS from node 0
        dfs(0, graph, path, result);

        return result;  // Return all collected paths
    }

    // Helper function to perform DFS traversal
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);  // Add the current node to the path

        // If we reach the target node (last node), save the current path
        if (node == graph.size() - 1) {
            result.push_back(path);  // Store a complete valid path
        } else {
            // Visit all neighbors of the current node
            for (int neighbor : graph[node]) {
                dfs(neighbor, graph, path, result);  // Recursive DFS call
            }
        }

        path.pop_back();  // Backtrack: remove the current node from path before returning
    }
};
