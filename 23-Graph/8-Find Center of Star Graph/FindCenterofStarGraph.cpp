// https://leetcode.com/problems/find-center-of-star-graph/description/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Extract the two nodes of the first edge
        int a = edges[0][0], b = edges[0][1];

        // Extract the two nodes of the second edge
        int c = edges[1][0], d = edges[1][1];

        // Check which node from the first edge is common in the second edge
        // Since the center node appears in all edges, the common node between
        // these two edges must be the center of the star graph
        if (a == c || a == d) {
            return a;  // 'a' is the center
        }

        // If 'a' is not common, then 'b' must be the center
        return b;
    }
};
