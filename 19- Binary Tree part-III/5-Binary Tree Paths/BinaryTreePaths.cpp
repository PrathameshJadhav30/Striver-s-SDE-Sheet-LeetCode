// https://leetcode.com/problems/binary-tree-paths/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
    public:
        // Main function to return all root-to-leaf paths
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> paths; // To store all the root-to-leaf paths
            if (!root) return paths; // Edge case: if tree is empty, return empty result
    
            // Call helper DFS function starting from the root
            dfs(root, "", paths);
            return paths;
        }
    
        // Helper function to perform DFS traversal
        void dfs(TreeNode* node, string path, vector<string>& paths) {
            if (!node) {
                return; // Base case: if node is NULL, just return
            }
    
            // If the path is not empty, append "->" before adding current node value
            if (!path.empty()) {
                path += "->";
            }
    
            // Append the current node's value to the path
            path += to_string(node->val);
    
            // If the current node is a leaf (no left or right children)
            if (!node->left && !node->right) {
                paths.push_back(path); // Add the completed path to the result vector
                return;
            }
    
            // Recursive DFS call on the left subtree
            dfs(node->left, path, paths);
    
            // Recursive DFS call on the right subtree
            dfs(node->right, path, paths);
        }
    };
    