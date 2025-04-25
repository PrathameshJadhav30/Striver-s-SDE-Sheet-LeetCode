// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // Base case: if the current node is null or matches either p or q
            // then return the current node
            if (root == nullptr || root == p || root == q) {
                return root;
            }
    
            // Recursively search in the left and right subtrees
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
            // If both left and right calls return non-null, current node is LCA
            if (left != nullptr && right != nullptr) {
                return root;
            }
    
            // Otherwise, return the non-null result from left or right subtree
            if (left) {
                return left;
            }
    
            return right;
        }
    };
    