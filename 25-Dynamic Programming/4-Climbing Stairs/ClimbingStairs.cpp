// https://leetcode.com/problems/climbing-stairs/description/
class Solution {
public:
    int climbStairs(int n) {
        // If there's only 1 step, there's only one way to climb it
        if (n == 1){
            return 1; 
        }

        // If there are 2 steps, there are two ways to climb: (1+1) or (2)
        if (n == 2){
            return 2; 
        } 

        // Initialize base values:
        // prev1 stores the number of ways to reach step (i-1)
        // prev2 stores the number of ways to reach step (i-2)
        int prev1 = 2; 
        int prev2 = 1; 
        int current;  // Will store ways to reach current step i

        // Start calculating from step 3 to n using bottom-up approach
        for (int i = 3; i <= n; i++) {
            // The total number of ways to reach step i is the sum of ways to reach
            // (i-1) and (i-2) steps (similar to Fibonacci)
            current = prev1 + prev2; 

            // Update prev2 and prev1 for next iteration
            prev2 = prev1;           
            prev1 = current;
        }

        // Return the number of ways to reach step n
        return current; 
    }
};
