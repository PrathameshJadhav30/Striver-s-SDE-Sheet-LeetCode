// https://leetcode.com/problems/flood-fill/description/
class Solution {
public:
    // DFS helper function to flood fill the image recursively
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int originalColor) {
        // If current row or column is out of image bounds, stop recursion
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) {
            return;
        }

        // If current pixel is not the same as the original color, do not fill
        if (image[r][c] != originalColor) {
            return;
        }

        // Change color of current pixel to the new color
        image[r][c] = newColor;

        // Recursively call DFS on all 4 adjacent pixels
        dfs(image, r + 1, c, newColor, originalColor); // Down
        dfs(image, r - 1, c, newColor, originalColor); // Up
        dfs(image, r, c + 1, newColor, originalColor); // Right
        dfs(image, r, c - 1, newColor, originalColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc]; // Store starting pixel's original color

        // If original color is same as new color, no changes needed
        if (originalColor == color) {
            return image;
        }

        // Start DFS from the starting pixel
        dfs(image, sr, sc, color, originalColor);

        return image; // Return the modified image
    }
};
