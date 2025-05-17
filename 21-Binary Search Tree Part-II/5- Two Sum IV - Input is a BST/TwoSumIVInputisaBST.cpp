// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description
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
    // Main function that initiates DFS and returns true if a pair summing to k is found
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen; // Set to store visited node values
        return dfs(root, k, seen); // Call helper function dfs
    }

    // Helper function for DFS traversal
    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) {
            // Base case: if the current node is null, return false
            return false;
        }

        // Check if the complement (k - current node's value) exists in the set
        if (seen.count(k - node->val)) {
            // If found, that means there's a previous node with value such that 
            // node->val + that value = k, so return true
            return true;
        }

        // Otherwise, insert the current node's value into the set
        seen.insert(node->val);

        // Continue DFS in the left and right subtrees
        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};
