// https://leetcode.com/problems/invert-binary-tree/description
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
        TreeNode* invertTree(TreeNode* root) {
            // Base case: if the current node is null, return null
            if (root == nullptr) {
                return nullptr;
            }
            
            // Recursively invert the left subtree
            TreeNode* leftSubtree = invertTree(root->left);
    
            // Recursively invert the right subtree
            TreeNode* rightSubtree = invertTree(root->right);
            
            // Swap the left and right subtrees
            root->left = rightSubtree;
            root->right = leftSubtree;
            
            // Return the root node (which now has its children inverted)
            return root;
        }
    };
    