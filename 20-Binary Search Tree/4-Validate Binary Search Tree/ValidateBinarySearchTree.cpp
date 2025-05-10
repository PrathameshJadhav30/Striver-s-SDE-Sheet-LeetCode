// https://leetcode.com/problems/validate-binary-search-tree/description/
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
    // Public function that initiates the recursive check for BST validity.
    bool isValidBST(TreeNode* root) {
        // Use long type for min and max values to avoid integer overflow issues.
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    // Helper function to recursively validate the BST.
    bool isValid(TreeNode* node, long minVal, long maxVal) {
        // Base case: An empty node is valid.
        if (!node){
            return true;
        }

        // The current node's value must lie strictly between minVal and maxVal.
        if (node->val <= minVal || node->val >= maxVal){
            return false;
        }

        // Recursively validate the left subtree:
        // All values in the left subtree must be less than the current node's value.
        // Recursively validate the right subtree:
        // All values in the right subtree must be greater than the current node's value.
        return isValid(node->left, minVal, node->val) &&
               isValid(node->right, node->val, maxVal);
    }
};
