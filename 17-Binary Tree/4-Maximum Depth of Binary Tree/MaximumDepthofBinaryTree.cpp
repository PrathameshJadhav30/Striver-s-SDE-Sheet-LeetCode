// https://leetcode.com/problems/maximum-depth-of-binary-tree/description
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
        int maxDepth(TreeNode* root) {
            // If the current node is null, we've reached beyond a leaf node
            // Return 0 because null node doesn't add to depth
            if (root == nullptr) 
            {
                return 0;
            }
    
            // Recursively calculate the depth of left subtree
            int leftDepth = maxDepth(root->left);
    
            // Recursively calculate the depth of right subtree
            int rightDepth = maxDepth(root->right);
    
            // Return the greater depth between left and right, plus 1 for the current node
            return 1 + max(leftDepth, rightDepth);
        }
    };
    