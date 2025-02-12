// https://leetcode.com/problems/bag-of-tokens/description/
class Solution {
    public:
        int bagOfTokensScore(vector<int>& tokens, int power) {
            int n = tokens.size();  // Get the size of the tokens array
            int maxScore = 0;       // Initialize maxScore to store the highest score achieved
    
            // Sort the tokens array in ascending order to manage tokens more efficiently
            sort(begin(tokens), end(tokens));
    
            int i = 0, j = n - 1;   // Two pointers: i for the smallest token, j for the largest
            int score = 0;          // Initialize the current score to 0
    
            // Continue until the two pointers meet
            while (i <= j) {
                if (power >= tokens[i]) {
                    // If we have enough power to take the smallest token, do so
                    power -= tokens[i];  // Decrease power by the value of tokens[i]
                    score++;             // Increase score by 1
                    i++;                 // Move the left pointer to the next token
    
                    // Update the maximum score achieved
                    maxScore = max(maxScore, score);
                } else if (score >= 1) {
                    // If we don't have enough power but have at least one score point,
                    // we can trade one score point to regain power using the largest token
                    power += tokens[j];  // Increase power by the value of tokens[j]
                    score--;             // Decrease score by 1
                    j--;                 // Move the right pointer to the previous token
                } else {
                    // If we can't take a token or regain power, return the maxScore
                    return maxScore;
                }
            }
    
            // Return the maximum score achieved after the loop
            return maxScore;
        }
    };
    