// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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
        // This pointer keeps track of the previously processed node in the traversal
        TreeNode* prev = nullptr;
    
        void flatten(TreeNode* root) {
            // Base case: if the current node is null, do nothing
            if (!root) {
                return;
            }
    
            // Recursively flatten the right subtree first (reverse preorder: right -> left -> root)
            flatten(root->right);
    
            // Recursively flatten the left subtree next
            flatten(root->left);
    
            // Rewire the current node's right pointer to point to the previously visited node
            root->right = prev;
    
            // Since we're converting to a linked list, set the left pointer to null
            root->left = nullptr;
    
            // Update the previously visited node to the current node
            prev = root;
        }
    };
    