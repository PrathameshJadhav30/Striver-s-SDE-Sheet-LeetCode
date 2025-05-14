//https://leetcode.com/problems/increasing-order-search-tree/description
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
    TreeNode* increasingBST(TreeNode* root) {
        // Create a dummy node to act as the starting point of the new tree
        TreeNode* dummy = new TreeNode(0);
        
        // Pointer to keep track of the current node in the new tree
        TreeNode* current = dummy;

        // Perform in-order traversal and rearrange the nodes
        inorder(root, current);

        // The new root of the tree is the right child of dummy
        return dummy->right;
    }

    // Helper function to perform in-order traversal
    void inorder(TreeNode* node, TreeNode*& current) {
        if (!node) {
            return; // Base case: if the node is null, do nothing
        }

        // Recursively traverse the left subtree
        inorder(node->left, current);

        // Disconnect the left child to satisfy the problem condition
        node->left = nullptr;

        // Append this node to the right of the current node in the new tree
        current->right = node;

        // Move the current pointer to this node
        current = node;

        // Recursively traverse the right subtree
        inorder(node->right, current);
    }
};
