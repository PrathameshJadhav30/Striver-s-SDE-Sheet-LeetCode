// https://leetcode.com/problems/assign-cookies/description/
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            // Sort both the greed factor array (g) and the size of cookies array (s)
            sort(begin(g), end(g)); 
            sort(begin(s), end(s));
    
            int m = g.size(); // Number of children
            int n = s.size(); // Number of cookies
    
            int i = 0, j = 0; // i tracks children, j tracks cookies
    
            // Iterate through both arrays to find the maximum number of content children
            while(i < m && j < n) {
                // If the current cookie can satisfy the current child
                if(g[i] <= s[j]) {
                    i++; // Move to the next child
                }
                j++; // Move to the next cookie
            }
            return i; // The number of children that received a cookie
        }
    };
    