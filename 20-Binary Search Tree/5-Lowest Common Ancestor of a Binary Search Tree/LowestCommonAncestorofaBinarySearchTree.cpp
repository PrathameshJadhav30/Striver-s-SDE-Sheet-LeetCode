// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
       
        // Base case: If the root is null, there's no LCA
        if (!root){
            return nullptr;
        } 
        
        // If both p and q are less than root, then LCA lies in the left subtree
        if (p->val < root->val && q->val < root->val) 
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If both p and q are greater than root, then LCA lies in the right subtree
        else if (p->val > root->val && q->val > root->val) 
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If p and q lie on either side of the root (or one is the root), then root is the LCA
        else {
            return root;
        }
    }
};
