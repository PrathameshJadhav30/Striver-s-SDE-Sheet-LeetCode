// https://leetcode.com/problems/symmetric-tree/description
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
        // Helper function to check if two trees are mirror images of each other
        bool isMirror(TreeNode* t1, TreeNode* t2) {
            // If both nodes are null, they are symmetric (mirror of each other)
            if (t1 == nullptr && t2 == nullptr){
                return true;
            } 
    
            // If only one of them is null, they are not symmetric
            if (t1 == nullptr || t2 == nullptr){
                return false;
            } 
    
            // Check current node values, and then recursively check
            // left subtree of t1 with right subtree of t2 and
            // right subtree of t1 with left subtree of t2
            return (t1->val == t2->val) &&
                   isMirror(t1->left, t2->right) &&
                   isMirror(t1->right, t2->left);
        }
    
        // Main function to check if the tree is symmetric
        bool isSymmetric(TreeNode* root) {
            // A tree is symmetric if it is a mirror of itself
            return isMirror(root, root);
        }
    };
    