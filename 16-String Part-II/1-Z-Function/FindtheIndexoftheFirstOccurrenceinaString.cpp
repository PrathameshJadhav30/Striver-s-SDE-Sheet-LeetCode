// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n = haystack.size(); // Length of the haystack string
            int m = needle.size();   // Length of the needle string
    
            // Loop through the haystack only up to the point where needle could still fit
            for (int i = 0; i <= n - m; ++i) {
                // Extract a substring from haystack starting at index i of length m
                // and compare it with the needle
                if (haystack.substr(i, m) == needle) {
                    return i; // Found the needle at index i
                }
            }
    
            // If loop completes without finding the needle, return -1
            return -1; 
        }
    };
    