// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
        // Variable to keep track of the maximum path sum found so far.
        int maxSum = INT_MIN; 
    
        // Helper function to compute the maximum gain from the current node
        int maxGain(TreeNode* node) 
        {
            // Base case: if the node is null, it contributes 0 to the path sum.
            if (!node){
                return 0;
            } 
          
            // Recursively get the maximum gain from the left child.
            // If the gain is negative, we ignore it by taking max with 0.
            int leftGain = max(maxGain(node->left), 0);  
    
            // Recursively get the maximum gain from the right child.
            // If the gain is negative, we ignore it by taking max with 0.
            int rightGain = max(maxGain(node->right), 0);
    
            // Compute the path sum if the path passes through the current node
            // and includes both left and right child contributions.
            int currentMaxPath = node->val + leftGain + rightGain;
    
            // Update the global maximum path sum if the current path is greater.
            maxSum = max(maxSum, currentMaxPath);
    
            // Return the maximum gain that this node can contribute to its parent.
            // We can only include one of the subtrees (left or right) to maintain the path constraint.
            return node->val + max(leftGain, rightGain);
        }
    
        // Main function that returns the maximum path sum in the binary tree.
        int maxPathSum(TreeNode* root) {
            maxGain(root); // Start the recursion from the root
            return maxSum; // Return the result stored in the global maxSum
        }
    };
    