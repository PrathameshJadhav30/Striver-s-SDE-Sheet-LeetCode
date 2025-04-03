// https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
    public:
        string reverseWords(string s) {
            // Step 1: Create a stringstream to split words by spaces
            stringstream ss(s);
            string word, result;
            vector<string> v; // Vector to store extracted words
    
            // Step 2: Extract words from the input string and store them in the vector
            while (ss >> word) { // Ignores multiple spaces automatically
                v.push_back(word);
            } 
    
            // Step 3: Reverse the order of words in the vector
            reverse(v.begin(), v.end());
    
            // Step 4: Construct the final result string
            for (int i = 0; i < v.size(); i++) {
                // Add a space before each word except the first one
                result += (i ? " " : "") + v[i];
            }
    
            // Step 5: Return the reversed string with words properly formatted
            return result;
        }
    };
    