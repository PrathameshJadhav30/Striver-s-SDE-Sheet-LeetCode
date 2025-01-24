// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Get the length of the input string
        int n = s.length();
        // Initialize variables to store the maximum length of the substring and the left pointer of the window
        int maxLength = 0, left = 0;
        // Use an unordered set to store unique characters in the current sliding window
        unordered_set<char> charSet;

        // Iterate through the string using the right pointer
        for (int right = 0; right < n; ++right) {
            // If the current character is already in the set, adjust the left pointer to maintain uniqueness
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]); // Remove the character at the left pointer
                left++; // Move the left pointer to the right
            }
            // Add the current character to the set
            charSet.insert(s[right]);
            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        // Return the length of the longest substring without repeating characters
        return maxLength;
    }
};
