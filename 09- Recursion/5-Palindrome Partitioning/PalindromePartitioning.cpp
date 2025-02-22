// https://leetcode.com/problems/palindrome-partitioning/description/
class Solution {
    public:
        // Function to check if a given string is a palindrome
        bool isPalindrome(string s) {
            string s2 = s; 
            reverse(s2.begin(), s2.end()); // Reverse the string
            return s == s2; // Check if original and reversed strings are the same
        }
    
        // Recursive function to find all palindrome partitions of the string
        void getAllParts(string s, vector<string>& partition, vector<vector<string>>& ans) {
            // Base case: If the string is empty, add the current partition to the result
            if (s.empty()) {
                ans.push_back(partition);
                return;
            }
    
            // Loop to partition the string in different ways
            for (int i = 0; i < s.size(); i++) {
                string part = s.substr(0, i + 1); // Extract substring from index 0 to i
    
                // If the substring is a palindrome, process further
                if (isPalindrome(part)) {
                    partition.push_back(part); // Add palindrome part to the current partition
                    getAllParts(s.substr(i + 1), partition, ans); // Recursively process the remaining string
                    partition.pop_back(); // Backtrack to explore other possibilities
                }
            }
        }
    
        // Main function to return all possible palindrome partitioning of a string
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans; // Stores all partitions
            vector<string> partition; // Temporary list to store the current partition
            
            getAllParts(s, partition, ans); // Start recursive function
    
            return ans; // Return the result containing all partitions
        }
    };