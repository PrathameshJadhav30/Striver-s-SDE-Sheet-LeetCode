// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution {
public:
    // Helper function to find the root parent of a node with path compression
    int find(int x, vector<int>& parent) {
        // If the current node is not its own parent, recursively find the root parent
        if (parent[x] != x){
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x]; // Return root parent
    }

    // Helper function to union two sets (returns true if union is successful)
    bool unionSet(int x, int y, vector<int>& parent) {
        int rootX = find(x, parent); // Find root of x
        int rootY = find(y, parent); // Find root of y

        // If both nodes have the same root, they are already connected
        if (rootX == rootY){
            return false; // No union performed (redundant edge)
        }

        // Union the sets by connecting rootX to rootY
        parent[rootX] = rootY;
        return true; // Union was successful
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If we have fewer connections than n - 1, we can't connect all computers
        if (connections.size() < n - 1){
            return -1;
        }

        // Initialize each computer as its own parent (disjoint sets)
        vector<int> parent(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        int components = n; // Initially, each node is its own component

        // Process each connection
        for (const auto& conn : connections) {
            // If union is successful, reduce the number of components
            if (unionSet(conn[0], conn[1], parent)) {
                components--;
            }
        }

        // To connect all components, we need (components - 1) operations
        return components - 1;
    }
};
