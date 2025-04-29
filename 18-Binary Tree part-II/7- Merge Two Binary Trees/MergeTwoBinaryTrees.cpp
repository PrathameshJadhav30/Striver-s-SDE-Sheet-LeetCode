// https://leetcode.com/problems/merge-two-binary-trees/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;                // Value of the node
 *     TreeNode *left;         // Pointer to the left child
 *     TreeNode *right;        // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Constructor with children
 * };
 */

 class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            // If the first tree node is null, return the second tree node
            if (!root1) {
                return root2;
            }
    
            // If the second tree node is null, return the first tree node
            if (!root2) {
                return root1;
            }
    
            // Both nodes are not null, so we add their values
            root1->val += root2->val;
    
            // Recursively merge the left children of both trees
            root1->left = mergeTrees(root1->left, root2->left);
    
            // Recursively merge the right children of both trees
            root1->right = mergeTrees(root1->right, root2->right);
    
            // Return the merged tree rooted at root1
            return root1;
        }
    };
    