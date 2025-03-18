// https://leetcode.com/problems/binary-tree-postorder-traversal/description
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
        //Helper function to perform postorder traversal recursively
        void postorder(TreeNode* root, vector<int>& res) {
            if (!root) { // Base case: if the node is null, return
                return;
            } 
            
            postorder(root->left, res);  // Recursively traverse left subtree
            postorder(root->right, res); // Recursively traverse right subtree
            res.push_back(root->val);    // Visit the current node (root)
        }
    
       
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res; // Stores the traversal result
            postorder(root, res); // Call the helper function
            return res; // Return the result
        }
    };
    