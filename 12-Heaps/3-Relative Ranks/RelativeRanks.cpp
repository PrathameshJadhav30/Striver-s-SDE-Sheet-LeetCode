// https://leetcode.com/problems/relative-ranks/description
class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& score) {
            int n = score.size();
            
            // Create a copy of the score array to sort
            vector<int> sortedScore = score;
            
            // Sort scores in descending order (highest first)
            sort(sortedScore.rbegin(), sortedScore.rend()); 
    
            // Map to store ranks corresponding to each score
            unordered_map<int, string> rankMap;
    
            // Assign ranks based on sorted order
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    rankMap[sortedScore[i]] = "Gold Medal"; // 1st place
                } 
                else if (i == 1) {
                    rankMap[sortedScore[i]] = "Silver Medal"; // 2nd place
                } 
                else if (i == 2) {
                    rankMap[sortedScore[i]] = "Bronze Medal"; // 3rd place
                } 
                else {
                    rankMap[sortedScore[i]] = to_string(i + 1); // 4th place and beyond
                } 
            }
    
            // Prepare the result vector
            vector<string> result(n);
            for (int i = 0; i < n; i++) {
                result[i] = rankMap[score[i]]; // Assign rank based on original scores
            }
    
            return result;
        }
    };
    