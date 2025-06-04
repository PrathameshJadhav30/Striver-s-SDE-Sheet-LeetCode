// https://leetcode.com/problems/network-delay-time/description
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the graph as an adjacency list.
        // Each node points to a list of (neighbor, time to reach) pairs.
        vector<vector<pair<int, int>>> graph(n + 1); 
        for (auto& edge : times) 
        {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w}); // Add a directed edge u -> v with weight w
        }

        // Step 2: Create a min-heap priority queue to process nodes with the smallest known time first.
        // Each element is a pair (time to reach, node).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});  // Start from node 'k' with time 0

        // Step 3: Initialize distances with infinity (INT_MAX), except the source node 'k'
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Step 4: Dijkstra's Algorithm
        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top(); // Get the node with the shortest known time
            minHeap.pop();

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : graph[node]) 
            {
                // If a shorter path to neighbor is found, update and push to queue
                if (dist[neighbor] > time + weight) 
                {
                    dist[neighbor] = time + weight;
                    minHeap.push({dist[neighbor], neighbor});
                }
            }
        }

        // Step 5: Find the longest time it took to reach any node
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            // If any node is unreachable, return -1
            if (dist[i] == INT_MAX){
              return -1;  
            } 
            // Update the maximum time
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime; // The network delay time
    }
};
