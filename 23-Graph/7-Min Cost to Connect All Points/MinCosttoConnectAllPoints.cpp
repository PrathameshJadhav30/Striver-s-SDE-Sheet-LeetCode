// https://leetcode.com/problems/min-cost-to-connect-all-points/description/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();  // Number of points

        // minDist[i] stores the minimum cost to connect point i to the MST
        vector<int> minDist(n, INT_MAX);

        // inMST[i] is true if point i is already included in the MST
        vector<bool> inMST(n, false);

        // Start with the first point (index 0), cost to add it is 0
        minDist[0] = 0;

        int totalCost = 0; // Final answer to store total cost of MST

        // Run the loop n times to include all n points in the MST
        for (int i = 0; i < n; i++) {
            int u = -1;

            // Find the point not in MST with the smallest distance
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && (u == -1 || minDist[v] < minDist[u])) {
                    u = v;
                }
            }

            // Include this point u in MST
            inMST[u] = true;

            // Add the cost of connecting point u
            totalCost += minDist[u];

            // Update the minimum distances for the remaining points
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    // Calculate the Manhattan distance between point u and point v
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    // If this distance is smaller than previously stored distance, update it
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }

        // Return the total cost to connect all points
        return totalCost;
    }
};
