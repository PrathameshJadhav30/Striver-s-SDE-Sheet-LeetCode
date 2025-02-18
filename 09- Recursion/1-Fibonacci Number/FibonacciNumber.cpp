// https://leetcode.com/problems/fibonacci-number/description/
class Solution {
    public:
        // Function to calculate the nth Fibonacci number using recursion
        int fib(int n) {
            // Base case: If n is 0 or 1, return n directly
            if(n <= 1){
                return n;
            }
    
            // Recursive case: Sum of the two preceding numbers
            return fib(n-1) + fib(n-2);
        }
    };
    