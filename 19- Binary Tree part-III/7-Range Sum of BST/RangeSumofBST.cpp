// https://leetcode.com/problems/range-sum-of-bst/description
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
        // Function to calculate the sum of all node values within the range [low, high]
        int rangeSumBST(TreeNode* root, int low, int high) {
            // Base case: if the node is NULL, return 0
            if (root == NULL)
            {
                return 0;
            } 
    
            int sum = 0;
    
            // If the current node's value lies within the range, add it to the sum
            if (root->val >= low && root->val <= high) 
            {
                sum += root->val;
            }
    
            // If the current node's value is greater than low,
            // then the left subtree might contain nodes within the range
            if (root->val > low) 
            {
                sum += rangeSumBST(root->left, low, high);
            }
    
            // If the current node's value is less than high,
            // then the right subtree might contain nodes within the range
            if (root->val < high) 
            {
                sum += rangeSumBST(root->right, low, high);
            }
    
            // Return the total sum accumulated
            return sum;
        }
    };
    