// https://leetcode.com/problems/search-in-a-binary-search-tree/description/
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
        TreeNode* searchBST(TreeNode* root, int val) {
            // Base case:
            // If the root is null or the root's value is equal to the target value,
            // return the root (which is either the node we are looking for or null)
            if (root == nullptr || root->val == val)
            {
                return root;
            }
    
            // If the target value is less than the root's value,
            // then the required node must lie in the left subtree
            if (val < root->val) 
            {
                return searchBST(root->left, val);
            }
    
            // Otherwise, the target value must lie in the right subtree
            return searchBST(root->right, val);
        }
    };
    