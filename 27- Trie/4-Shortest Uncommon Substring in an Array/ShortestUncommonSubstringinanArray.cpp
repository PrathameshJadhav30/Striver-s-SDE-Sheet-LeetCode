// https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        
        // Map to store all substrings and the set of string indices they appear in
        unordered_map<string, unordered_set<int>> substringMap;

        // Step 1: Generate all substrings of each string and record the indices where they appear
        for (int i = 0; i < n; i++) {
            string& s = arr[i];
            int len = s.size();

            for (int l = 1; l <= len; l++) { // l = length of substring
                for (int start = 0; start + l <= len; start++) {
                    string sub = s.substr(start, l);  // extract substring
                    substringMap[sub].insert(i);      // map substring to the string index
                }
            }
        }

        vector<string> answer(n, "");  // Result vector initialized with empty strings

        // Step 2: For each string, find the shortest unique substring
        for (int i = 0; i < n; i++) {
            string& s = arr[i];
            int len = s.size();
            string result = "";  // Store the shortest unique substring for arr[i]

            // Try substrings of increasing lengths
            for (int l = 1; l <= len; l++) {
                for (int start = 0; start + l <= len; start++) {
                    string sub = s.substr(start, l);

                    // Check if the substring appears only in arr[i]
                    if (substringMap[sub].size() == 1 && substringMap[sub].count(i)) {
                        // If result not set or found smaller lexicographical substring
                        if (result == "" || sub < result) {
                            result = sub;
                        }
                    }
                }
                // Break early once we find any shortest valid substring
                if (!result.empty()) {
                    break;
                }
            }
            answer[i] = result;  // Assign final result for current string
        }

        return answer;
    }
};
