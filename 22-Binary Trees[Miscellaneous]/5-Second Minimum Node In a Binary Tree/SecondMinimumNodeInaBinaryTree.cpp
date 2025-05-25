// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
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
    int findSecondMinimumValue(TreeNode* root) {
        // If the root is null or it is a leaf node, there's no second minimum
        if (!root || (!root->left && !root->right)) {
            return -1;
        }

        // Get the values of the left and right child
        int leftVal = root->left->val;
        int rightVal = root->right->val;

        // If left child's value is equal to root's value, we need to search deeper on the left
        if (leftVal == root->val) {
            leftVal = findSecondMinimumValue(root->left);
        }

        // If right child's value is equal to root's value, we need to search deeper on the right
        if (rightVal == root->val) {
            rightVal = findSecondMinimumValue(root->right);
        }

        // If both leftVal and rightVal have valid second minimums, return the smaller one
        if (leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        }
        // If only leftVal is valid, return it
        else if (leftVal != -1) {
            return leftVal;
        }
        // If only rightVal is valid, return it
        else {
            return rightVal;
        }
    }
};
