// https://leetcode.com/problems/same-tree/description
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
        // Function to check if two binary trees are the same
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // If both nodes are null, this part of the tree is the same
            if (p == nullptr && q == nullptr) 
            {
                return true;
            }
            
            // If one of the nodes is null or their values are different, trees are not the same
            if (p == nullptr || q == nullptr || p->val != q->val) 
            {
                return false;
            }
            
            // Recursively check the left subtree and right subtree
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };
    