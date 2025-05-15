// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description
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
    // Variable to store the cumulative sum of node values
    int sum = 0;

    // Main function to convert BST to Greater Sum Tree
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);  // Start reverse in-order traversal
        return root;           // Return the updated root node
    }

    // Helper function to perform reverse in-order traversal
    void reverseInorder(TreeNode* node) {
        if (!node) {
            return;  // Base case: if the node is null, just return
        }

        // First visit the right subtree (larger values)
        reverseInorder(node->right);

        // Update the sum and the current node's value
        sum += node->val;      // Add current node's value to the running sum
        node->val = sum;       // Update current node's value with the new sum

        // Then visit the left subtree (smaller values)
        reverseInorder(node->left);
    }
};
