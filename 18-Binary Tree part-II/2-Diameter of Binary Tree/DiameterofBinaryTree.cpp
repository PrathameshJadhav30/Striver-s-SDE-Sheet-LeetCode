// https://leetcode.com/problems/diameter-of-binary-tree/description
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
        // Variable to store the maximum diameter found during DFS
        int maxDiameter = 0;
    
        // Helper function to calculate height of the tree
        // while updating the maximum diameter
        int height(TreeNode* node) {
            // Base case: if the node is null, height is 0
            if (!node){
                return 0;
            }
    
            // Recursively compute the height of left and right subtrees
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
    
            // Diameter at the current node is leftHeight + rightHeight
            // Update the maxDiameter if this is the largest seen so far
            maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    
            // Height of the current node = 1 + max of left/right heights
            return 1 + max(leftHeight, rightHeight);
        }
    
        // Main function to return the diameter of the binary tree
        int diameterOfBinaryTree(TreeNode* root) 
        {
            // Start DFS traversal from the root
            height(root);  
    
            // maxDiameter holds the result after DFS
            return maxDiameter;
        }
    };
    