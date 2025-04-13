// https://leetcode.com/problems/count-and-say/description/
class Solution {
    public:
        string countAndSay(int n) {
            // Base string for the sequence
            string result = "1";
    
            // Generate the sequence up to the nth term
            for (int i = 1; i < n; i++) {
                string current = "";  // Temporary string to build the next sequence term
                int Count = 1;        // Counter to count repeated digits
    
                // Loop through the current result string
                for (int j = 0; j < result.size(); j++) {
                    // If the next character is the same, increase the count
                    if (j + 1 < result.size() && result[j] == result[j + 1]) {
                        Count++;
                    } else {
                        // Otherwise, append the count and the digit to 'current'
                        current += to_string(Count) + result[j];
                        Count = 1; // Reset the count for the next group
                    }
                }
    
                // Update result to the current term for the next iteration
                result = current;
            }
    
            // Return the final result after n iterations
            return result;
        }
    };
    