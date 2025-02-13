// https://leetcode.com/problems/boats-to-save-people/description/
class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            int n = people.size();  // Get the number of people
            
            // Sort the array to arrange weights in increasing order
            sort(begin(people), end(people));
            
            int i = 0, j = n - 1;  // Two pointers: i (lightest), j (heaviest)
            int boats = 0;  // Count of boats needed
            
            // Use a two-pointer approach to pair the heaviest with the lightest
            while (i <= j) {
                // If the sum of weights of i and j is within the limit, pair them
                if (people[j] + people[i] <= limit) {
                    i++;  // Move the left pointer to the next person
                    j--;  // Move the right pointer to the next lighter person
                } else {
                    // If the heaviest person can't be paired, send them alone
                    j--;
                }
                boats++;  // A boat is used in each iteration
            }
    
            return boats;  // Return the total number of boats needed
        }
    };
    