// https://leetcode.com/problems/rotting-oranges/description/
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size();  // Number of rows
            int n = grid[0].size();  // Number of columns
    
            vector<vector<int>> visited = grid;  // Copy of the grid to track changes
            queue<pair<int, int>> q;  // Queue to store rotten oranges
    
            int countFreshOrange = 0;  // Count of fresh oranges
    
            // Step 1: Identify all rotten oranges and count fresh ones
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j] == 2) {
                        q.push({i, j});  // Store rotten orange coordinates
                    }
                    if (visited[i][j] == 1) {
                        countFreshOrange++;  // Count fresh oranges
                    }
                }
            }
    
            // Step 2: Edge cases handling
            if (countFreshOrange == 0) return 0;  // No fresh oranges → no time needed
            if (q.empty()) return -1;  // No rotten oranges to spread the rot → impossible case
    
            int minutes = -1;  // Initialize time counter
    
            // Define directions for 4-way movement: right, left, down, up
            vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
            // Step 3: BFS traversal to rot fresh oranges
            while (!q.empty()) {
                int size = q.size();  // Number of oranges to process at current time step
    
                while (size--) {  // Process all oranges at the current level
                    auto [x, y] = q.front();
                    q.pop();
    
                    // Check all 4 adjacent directions
                    for (auto [dx, dy] : dirs) {
                        int i = x + dx;
                        int j = y + dy;
    
                        // If the adjacent cell contains a fresh orange, rot it
                        if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                            visited[i][j] = 2;  // Mark it as rotten
                            countFreshOrange--;  // Decrease the count of fresh oranges
                            q.push({i, j});  // Add it to the queue for further processing
                        }
                    }
                }
                minutes++;  // Increment time after processing all oranges at the current level
            }
    
            // Step 4: Check if any fresh oranges remain
            return (countFreshOrange == 0) ? minutes : -1;
        }
    };