// https://leetcode.com/problems/permutation-sequence/description/
class Solution {
    public:
        // Recursive function to generate all possible permutations of numbers 1 to n
        void Perm(int indx, int curr, int n, vector<bool>& taken, vector<int>& sequences) {
            // Base case: if indx reaches n, we have a complete permutation
            if (indx == n) {
                sequences.push_back(curr); // Store the permutation in the list
                return;
            }
    
            // Loop through all numbers from 1 to n
            for (int i = 1; i <= n; i++) {
                // If the number is not yet used in the current permutation
                if (!taken[i]) {  
                    taken[i] = true;  // Mark the number as used
                    Perm(indx + 1, curr * 10 + i, n, taken, sequences); // Recursively build the permutation
                    taken[i] = false;  // Backtrack: unmark the number for the next iteration
                }
            }
        }
    
        // Function to get the k-th permutation of numbers 1 to n
        string getPermutation(int n, int k) {
            vector<int> sequences;  // Stores all generated permutations
            vector<bool> taken(n + 1, false); // Keeps track of used numbers (1-based index)
            
            // Generate all permutations
            Perm(0, 0, n, taken, sequences);
    
            return to_string(sequences[k - 1]); // Convert the k-th permutation to string and return
        }
    };