// https://leetcode.com/problems/time-needed-to-buy-tickets/description
class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            int time = 0; // Variable to store the total time taken
            int n = tickets.size(); // Get the number of people in the queue
            
            // Iterate through the queue
            for (int i = 0; i < n; i++) 
            {
                // If the current person is before or at position 'k'
                if (i <= k)
                {
                    // They will buy up to 'tickets[k]' tickets
                    time += min(tickets[i], tickets[k]);
                } 
                else
                {
                    // People after 'k' will only contribute up to 'tickets[k] - 1' seconds
                    // because they leave before 'k' finishes all their tickets.
                    time += min(tickets[i], tickets[k] - 1);
                }
            }
            
            return time; // Return total time required for person at index 'k'
        }
    };
    