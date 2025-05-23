// https://leetcode.com/problems/sum-of-left-leaves/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right; // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case: if the current node is null, return 0
        if (root == nullptr){
           return 0;
        } 

        int sum = 0;

        // Check if the left child exists and is a leaf node (has no children)
        if (root->left && !root->left->left && !root->left->right) {
            // Add the value of the left leaf to the sum
            sum += root->left->val;
        }

        // Recursively call the function on the left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        // Return the total sum of left leaves
        return sum;
    }
};
