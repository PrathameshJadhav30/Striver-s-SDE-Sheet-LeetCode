// https://leetcode.com/problems/path-sum/description
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
        bool hasPathSum(TreeNode* root, int targetSum) {
            
            // Base case: if the current node is null, no path exists
            if (root == nullptr) {
                return false;
            } 
            
            // Check if the current node is a leaf node
            // If yes, check if the node's value equals the remaining targetSum
            if (root->left == nullptr && root->right == nullptr) {
                return root->val == targetSum;
            }
    
            // Subtract the current node's value from targetSum
            // and recursively check the left and right subtrees
            int remainingSum = targetSum - root->val;
    
            // Return true if either subtree has a valid path sum
            return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
        }
    };
    
    