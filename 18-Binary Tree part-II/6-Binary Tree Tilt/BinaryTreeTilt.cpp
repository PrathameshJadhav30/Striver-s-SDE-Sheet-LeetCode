// https://leetcode.com/problems/binary-tree-tilt/description
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
        // Variable to store the total tilt of all nodes
        int totalTilt = 0;
    
        // Helper function to perform post-order traversal and compute tilt
        int dfs(TreeNode* root)
        {
            // Base case: if the node is null, return 0
            if (!root) {
                return 0;
            }
    
            // Recursively find the sum of left and right subtrees
            int leftSum = dfs(root->left);
            int rightSum = dfs(root->right);
    
            // Calculate the tilt for the current node
            int nodeTilt = abs(leftSum - rightSum);
    
            // Add the current node's tilt to the total tilt
            totalTilt += nodeTilt;
    
            // Return the sum of values under this node (including itself)
            return leftSum + rightSum + root->val;
        }
    
        // Main function to find the total tilt of the tree
        int findTilt(TreeNode* root) {
            dfs(root); // Start DFS traversal from root
            return totalTilt; // Return the accumulated total tilt
        }
    };
    