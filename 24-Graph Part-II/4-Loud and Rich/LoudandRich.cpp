// https://leetcode.com/problems/loud-and-rich/description/
class Solution {
public:
    vector<vector<int>> graph;     // Adjacency list to store richer relationships
    vector<int> answer;            // answer[i] = the person who is quietest among those richer than or equal to person i
    vector<int> quiet;             // Stores the quietness level of each person

    // DFS function to compute the quietest richer-or-equal person for a given node
    int dfs(int node) {
        // If already computed, return stored result to avoid recomputation
        if (answer[node] != -1) {
            return answer[node];
        }

        // Initially assume the quietest person is the person themselves
        answer[node] = node;

        // Traverse all richer persons of the current person
        for (int richerPerson : graph[node]) {
            int candidate = dfs(richerPerson);  // Get quietest person for richerPerson
            // Update if a quieter person is found
            if (quiet[candidate] < quiet[answer[node]]) {
                answer[node] = candidate;
            }
        }

        return answer[node];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quietInput) {
        int n = quietInput.size();     // Number of people
        quiet = quietInput;           // Copy the quiet array

        graph.resize(n);              // Resize graph for n people

        // Build the graph: edge from 'poor' -> 'rich' (reverse of richer relation)
        for (auto& pair : richer) {
            int rich = pair[0];
            int poor = pair[1];
            graph[poor].push_back(rich);  // rich is richer than poor
        }

        // Initialize answer with -1 indicating "not yet computed"
        answer.assign(n, -1);

        // Run DFS for each person to compute their answer
        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return answer;  // Return the final result
    }
};
