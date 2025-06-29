// https://leetcode.com/problems/number-of-matching-subsequences/description/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Step 1: Store all indices of characters in 's' using a hash map
        // Each character maps to a vector of indices where it appears in 's'
        unordered_map<char, vector<int>> char_indices;
        for (int i = 0; i < s.size(); i++) {
            char_indices[s[i]].push_back(i);
        }

        // Lambda function to check if a word is a subsequence of 's'
        auto isSubsequence = [&](const string& word) -> bool {
            int prev_index = -1;  // Initialize previous matched index to -1
            for (char c : word) {
                // If character 'c' doesn't exist in 's', it's not a subsequence
                if (char_indices.find(c) == char_indices.end())
                    return false;

                // Use binary search to find the smallest index > prev_index
                const vector<int>& indices = char_indices[c];
                auto it = upper_bound(indices.begin(), indices.end(), prev_index);
                
                // If no such index exists, character order is broken
                if (it == indices.end())
                    return false;

                // Update prev_index to the current found index
                prev_index = *it;
            }
            return true; // All characters matched in order
        };

        // Step 2: Count how many words in the list are subsequences of 's'
        int count = 0;

        // Memoization to avoid recomputation for duplicate words
        unordered_map<string, bool> memo;

        for (string& word : words) {
            // If word already checked before, use memoized result
            if (memo.count(word)) {
                if (memo[word]) count++;
            } else {
                // Check if it's a subsequence and cache the result
                bool isSub = isSubsequence(word);
                memo[word] = isSub;
                if (isSub) count++;
            }
        }

        return count; // Return total number of matching subsequences
    }
};
