// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description
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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;  // Initialize the minimum difference to a large value
        TreeNode* prev = nullptr;  // To keep track of the previous node in in-order traversal
        inorder(root, prev, minDiff);  // Start in-order traversal
        return minDiff;  // Return the minimum difference found
    }
    
    // In-order traversal function
    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) {
            return;  // Base case: if the node is null, do nothing
        }

        // Traverse the left subtree
        inorder(node->left, prev, minDiff);

        // Process the current node
        if (prev != nullptr) {
            // Compute the difference between current and previous node values
            minDiff = min(minDiff, node->val - prev->val);
        }
        // Update the previous node to current node
        prev = node;

        // Traverse the right subtree
        inorder(node->right, prev, minDiff);
    }
};
