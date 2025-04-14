// https://leetcode.com/problems/compare-version-numbers/description/
class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int i = 0, j = 0;  // Pointers to iterate through version1 and version2
            int n1 = version1.size();
            int n2 = version2.size();
    
            // Loop until both version strings are fully traversed
            while (i < n1 || j < n2) {
                int num1 = 0, num2 = 0;
    
                // Extract integer value from current segment of version1
                while (i < n1 && version1[i] != '.') {
                    num1 = num1 * 10 + (version1[i] - '0');  // Convert char to int
                    i++;
                }
    
                // Extract integer value from current segment of version2
                while (j < n2 && version2[j] != '.') {
                    num2 = num2 * 10 + (version2[j] - '0');  // Convert char to int
                    j++;
                }
    
                // Compare the current revision numbers
                if (num1 < num2) {
                    return -1;  // version1 is less than version2
                } 
                if (num1 > num2) {
                    return 1;   // version1 is greater than version2
                }
    
                // If equal, move to the next segment (skip the dot)
                i++;
                j++;
            }
    
            // All revisions are equal
            return 0;
        }
    };
    