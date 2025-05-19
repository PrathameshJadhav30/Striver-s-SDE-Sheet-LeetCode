// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description
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
    // Global variable to store the maximum sum of any BST in the tree
    int answer = INT_MIN;

    /**
     * Helper function to perform post-order traversal and determine BST properties.
     * Returns a vector of 3 elements:
     * [0] - minimum value in the current subtree
     * [1] - maximum value in the current subtree
     * [2] - sum of all values in the current subtree
     */
    vector<int> solve(TreeNode* node) {
        // Base case: if the node is null, return default values for a valid BST
        if (node == NULL){
            return {INT_MAX, INT_MIN, 0}; // min = +∞, max = -∞, sum = 0
        }

        // Recursively solve for the left and right subtrees
        vector<int> left = solve(node->left);
        vector<int> right = solve(node->right);

        // Check if the current node forms a valid BST with its left and right children
        // Condition: max value in left subtree < current node's value < min value in right subtree
        if (left[1] >= node->val || right[0] <= node->val) {
            // Not a valid BST, return invalid indicators
            return {INT_MIN, INT_MAX, 0}; // Inverted min/max to signal invalid BST
        }

        // Calculate the sum of the current valid BST
        int currSum = left[2] + right[2] + node->val;

        // Update the global maximum if this subtree has a higher sum
        answer = max(answer, currSum);

        // Return the min, max, and total sum of this subtree to parent call
        return {
            min(node->val, left[0]), // minimum value in the current subtree
            max(node->val, right[1]), // maximum value in the current subtree
            currSum                   // sum of values in the current subtree
        };
    }

public:
    /**
     * Main function to start the traversal and return the final answer.
     * If no valid BST is found (answer < 0), return 0.
     */
    int maxSumBST(TreeNode* root) {
        solve(root);
        return max(0, answer); // Ensure non-negative result as per problem statement
    }
};
