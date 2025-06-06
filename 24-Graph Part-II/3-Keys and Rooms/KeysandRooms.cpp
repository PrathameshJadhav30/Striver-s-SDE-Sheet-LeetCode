// https://leetcode.com/problems/keys-and-rooms/description/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();  // Total number of rooms
        vector<bool> visited(n, false);  // Boolean array to track visited rooms
        
        // Lambda function for Depth-First Search (DFS)
        function<void(int)> dfs = [&](int room) {
            visited[room] = true;  // Mark the current room as visited
            
            // Iterate through all keys found in the current room
            for (int key : rooms[room]) {
                // If the room corresponding to the key hasn't been visited
                if (!visited[key]) {
                    dfs(key);  // Recursively visit the room
                }
            }
        };
        
        dfs(0);  // Start DFS from room 0 (only unlocked room initially)
    
        // After DFS, check if all rooms were visited
        for (bool v : visited) {
            if (!v) return false;  // If any room wasn't visited, return false
        }
        return true;  // All rooms were visited
    }
};
