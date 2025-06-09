// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // Adjacency lists to store red and blue edges separately
        vector<vector<int>> redAdj(n), blueAdj(n);

        // Fill red adjacency list
        for (auto& edge : redEdges) {
            redAdj[edge[0]].push_back(edge[1]);
        }

        // Fill blue adjacency list
        for (auto& edge : blueEdges) {
            blueAdj[edge[0]].push_back(edge[1]);
        }

        // Initialize result vector with -1, meaning unreachable by default
        vector<int> result(n, -1);

        // visited[node][color] tracks if a node is visited via a red(0) or blue(1) edge
        vector<vector<bool>> visited(n, vector<bool>(2, false));

        // Queue to store {node, steps from start, last edge color used}
        // lastColor: -1 = no color yet, 0 = red, 1 = blue
        queue<tuple<int, int, int>> q;

        // Start from node 0 with no edge taken yet
        q.push({0, 0, -1});

        // Mark node 0 visited via both red and blue initially
        visited[0][0] = visited[0][1] = true;

        // Distance to starting node is 0
        result[0] = 0;

        // Begin BFS traversal
        while (!q.empty()) {
            auto [node, steps, lastColor] = q.front(); // Unpack current state
            q.pop();

            // If last edge was not red, we can try red edges now
            if (lastColor != 0) {
                for (int nei : redAdj[node]) {
                    if (!visited[nei][0]) {
                        visited[nei][0] = true;                      // Mark red visit
                        q.push({nei, steps + 1, 0});                // Move to neighbor using red edge
                        if (result[nei] == -1) result[nei] = steps + 1; // First time reaching this node
                    }
                }
            }

            // If last edge was not blue, we can try blue edges now
            if (lastColor != 1) {
                for (int nei : blueAdj[node]) {
                    if (!visited[nei][1]) {
                        visited[nei][1] = true;                      // Mark blue visit
                        q.push({nei, steps + 1, 1});                // Move to neighbor using blue edge
                        if (result[nei] == -1) result[nei] = steps + 1; // First time reaching this node
                    }
                }
            }
        }

        // Return shortest paths from node 0 to all nodes with alternating colors
        return result;
    }
};
