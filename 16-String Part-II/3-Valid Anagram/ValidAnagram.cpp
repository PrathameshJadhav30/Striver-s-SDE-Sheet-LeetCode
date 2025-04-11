// https://leetcode.com/problems/valid-anagram/description
class Solution {
    public:
        bool isAnagram(string s, string t)
        {
            // If the lengths are not equal, they cannot be anagrams
            if (s.length() != t.length())
                return false;
    
            // Create an array to store frequency of each character (assuming lowercase letters only)
            int count[26] = {0};  
    
            // Count the frequency of each character in string 's'
            for (int i = 0; i < s.length(); i++) 
            {
                count[s[i] - 'a']++;
            }
    
            // Subtract the frequency based on characters in string 't'
            for (int i = 0; i < t.length(); i++)
            {
                count[t[i] - 'a']--;
            }
    
            // Check if all elements in the count array are zero
            // If not, then 's' and 't' are not anagrams
            for (int i = 0; i < 26; i++)
            {
                if (count[i] != 0)
                    return false;
            }
    
            // If all character counts are zero, the strings are anagrams
            return true;
        }
    };
    