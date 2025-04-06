// https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
    public:
        int myAtoi(string s) {
            int i = 0;
            int n = s.length();
            
            // Step 1: Skip leading whitespaces
            while (i < n && s[i] == ' ') 
            {
                i++;
            }
    
            // Step 2: Handle optional '+' or '-' sign
            int sign = 1; // Default is positive
            if (i < n && (s[i] == '+' || s[i] == '-'))
            {
                if (s[i] == '-') {
                    sign = -1; // Set sign to negative
                }
                i++; // Move past the sign
            }
    
            // Step 3: Read digits and build the number
            long result = 0; // Use long to detect overflow before converting to int
            while (i < n && isdigit(s[i])) 
            {
                int digit = s[i] - '0'; // Convert char to int
                result = result * 10 + digit; // Append digit to result
    
                // Step 4: Check for overflow and clamp if necessary
                if (sign * result <= INT_MIN) {
                    return INT_MIN;
                }
                if (sign * result >= INT_MAX) {
                    return INT_MAX;
                }
    
                i++; // Move to next character
            }
    
            // Step 5: Return final result with sign applied
            return (int)(sign * result);
        }
    };
    