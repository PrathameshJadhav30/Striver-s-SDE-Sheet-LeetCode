// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
class Solution {
public:
    // Union-Find (Disjoint Set Union) parent mapping
    unordered_map<int, int> parent;

    // Find function with path compression
    int find(int x) {
        // If x is not in parent map, initialize it to itself
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        // Path compression to flatten the tree
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union function to connect two nodes
    void unite(int x, int y) {
        parent[find(x)] = find(y); // Connect root of x to root of y
    }

    int removeStones(vector<vector<int>>& stones) {
        // Connect each stone's row and column in the union-find structure
        // Offset columns by 10001 to distinguish from rows (since 0 <= x, y <= 10^4)
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset column to avoid collision with row ids
            unite(row, col); // Union the row and column
        }

        // Count the number of unique connected components
        unordered_set<int> unique_roots;
        for (auto& stone : stones) {
            unique_roots.insert(find(stone[0])); // Find the root of each stone's row
        }

        // The maximum stones that can be removed is total stones - number of components
        return stones.size() - unique_roots.size();
    }
};
