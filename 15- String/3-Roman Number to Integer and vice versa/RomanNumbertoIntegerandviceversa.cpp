// https://leetcode.com/problems/roman-to-integer/description/
class Solution {
    public:
        int romanToInt(string s) {
            // Map each Roman numeral to its corresponding integer value
            unordered_map<char, int> roman{
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
    
            int total = 0;       // To store the final integer result
            int prevValue = 0;   // To store the value of the previous Roman character for comparison
    
            // Traverse the string from right to left
            for (int i = s.length() - 1; i >= 0; i--) {
                int currValue = roman[s[i]];  // Get the integer value of the current Roman character
    
                // If the current value is less than the previous value,
                // it means we need to subtract (e.g., IV -> 5 - 1 = 4)
                if (currValue < prevValue) {
                    total -= currValue;
                }    
                else {
                    // Otherwise, just add the current value to the total
                    total += currValue;
                }
    
                // Update the previous value to the current one for the next iteration
                prevValue = currValue;
            }
    
            return total;  // Return the final converted integer
        }
    };
    