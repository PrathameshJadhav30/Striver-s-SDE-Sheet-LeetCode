// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize the distance vector with INT_MAX (representing infinity)
        // Initially, we assume all cities are unreachable from src
        vector<int> dist(n, INT_MAX);
        
        // The cost to reach the source city from itself is always 0
        dist[src] = 0;

        // Perform at most k + 1 edge relaxations (because k stops => k+1 edges)
        for (int i = 0; i <= k; i++) 
        {
            // Make a temporary copy of the current distance array
            // This ensures that we only use information from the previous iteration
            vector<int> temp = dist;

            // Iterate over all flights and try to relax edges
            for (auto& flight : flights) {
                int u = flight[0];      // source city
                int v = flight[1];      // destination city
                int price = flight[2];  // flight cost

                // If the source city 'u' is reachable,
                // and taking this flight offers a cheaper cost to 'v', update it
                if (dist[u] != INT_MAX && dist[u] + price < temp[v]) 
                {
                    temp[v] = dist[u] + price;
                }
            }

            // Update the distance array with new shortest distances after this round
            dist = temp;
        }

        // If destination city is still unreachable, return -1
        // Otherwise, return the cheapest price to reach destination
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
