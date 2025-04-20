// https://leetcode.com/problems/balanced-binary-tree/description
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
    
        // Helper function to check the height of the tree rooted at 'node'
        // Returns -1 if the subtree is not height-balanced
        int checkHeight(TreeNode* node) {
            // Base case: If node is null, height is 0
            if (node == nullptr) {
                return 0;
            }
    
            // Recursively get height of left subtree
            int leftHeight = checkHeight(node->left);
            // If left subtree is unbalanced, return -1
            if (leftHeight == -1) {
                return -1;
            }
    
            // Recursively get height of right subtree
            int rightHeight = checkHeight(node->right);
            // If right subtree is unbalanced, return -1
            if (rightHeight == -1) {
                return -1;
            }
    
            // If height difference is greater than 1, tree is unbalanced
            if (abs(leftHeight - rightHeight) > 1) {
                return -1;
            }
    
            // Return height of current subtree
            return 1 + max(leftHeight, rightHeight);
        }
    
        // Main function to determine if tree is height-balanced
        bool isBalanced(TreeNode* root) {
            // If checkHeight returns -1, tree is not balanced
            return checkHeight(root) != -1;
        }
    };
    