// https://leetcode.com/problems/find-the-town-judge/description/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // inDegree[i] = number of people who trust person i
        // outDegree[i] = number of people person i trusts
        vector<int> inDegree(n + 1, 0);   
        vector<int> outDegree(n + 1, 0); 

        // Loop through each trust relationship
        for (auto& t : trust) 
        {
            int a = t[0], b = t[1];
            outDegree[a]++; // a trusts someone → not a judge
            inDegree[b]++;  // b is trusted by a
        }

        // Check each person from 1 to n
        for (int i = 1; i <= n; i++) 
        {
            // The judge should be trusted by n - 1 people
            // And should not trust anyone
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
                return i; // Found the judge
        }

        return -1; // No judge found
    }
};
