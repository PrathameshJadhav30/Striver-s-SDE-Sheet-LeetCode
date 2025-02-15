// https://leetcode.com/problems/maximum-ice-cream-bars/description/
class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            // Sort the costs in ascending order to buy the cheapest ice creams first
            sort(costs.begin(), costs.end());
    
            int count = 0; // Counter to track the number of ice creams that can be bought
    
            // Iterate through the sorted costs
            for(int i = 0; i < costs.size(); i++) {
                // If the current ice cream cost is greater than the remaining coins, stop purchasing
                if(costs[i] > coins) {
                    return count;
                } else {
                    // Purchase the ice cream, increment count, and reduce the available coins
                    count++;
                    coins -= costs[i];
                }
            }
            // Return the total number of ice creams that can be bought
            return count;
        }
    };