// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description
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
    // Variable to store the minimum absolute difference found
    int minDiff = INT_MAX;

    // Pointer to store the previous node visited in in-order traversal
    TreeNode* prev = nullptr;

    // In-order traversal: visits nodes in increasing order for BST
    void inorder(TreeNode* root) 
    {
        // Base case: if root is null, return
        if (!root){
            return;
        } 

        // Traverse the left subtree
        inorder(root->left);

        // Process current node:
        // If there is a previously visited node, compute the difference
        // between current node's value and previous node's value
        if (prev != nullptr) 
        {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }

        // Update prev to the current node before moving to the right subtree
        prev = root;

        // Traverse the right subtree
        inorder(root->right);
    }

    // Main function to be called, returns the minimum absolute difference
    int getMinimumDifference(TreeNode* root) {
        // Start in-order traversal from the root
        inorder(root);

        // Return the smallest difference found
        return minDiff;
    }
};
