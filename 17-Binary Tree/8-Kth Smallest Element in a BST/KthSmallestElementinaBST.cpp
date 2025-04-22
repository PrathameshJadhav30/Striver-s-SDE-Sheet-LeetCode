// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description
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
        int count = 0;    // Counter to keep track of number of visited nodes during inorder traversal
        int result = 0;   // Stores the kth smallest value once found
    
        // Helper function to perform inorder traversal
        void inorder(TreeNode* root, int k) {
            if (!root) {
                return; // Base case: if root is null, return
            }
    
            // Traverse the left subtree
            inorder(root->left, k);
    
            // Visit the current node
            count++; // Increment the counter as we visit a node
    
            // If count matches k, we found the kth smallest
            if (count == k) {
                result = root->val;
                return;
            }
    
            // Traverse the right subtree
            inorder(root->right, k);
        }
    
        // Main function to return kth smallest element
        int kthSmallest(TreeNode* root, int k) {
            inorder(root, k); // Start inorder traversal
            return result;    // Return the result once traversal is complete
        }
    };
    