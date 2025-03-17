// https://leetcode.com/problems/binary-tree-preorder-traversal/description
class Solution {
    public:
        // Helper function to perform preorder traversal recursively
        void preorder(TreeNode* root, vector<int>& result) {
            if (!root) return;  // Base case: If the node is NULL, return
    
            result.push_back(root->val);   // Step 1: Visit the root node (Add to result)
            preorder(root->left, result);  // Step 2: Recursively visit the left subtree
            preorder(root->right, result); // Step 3: Recursively visit the right subtree
        }
    
        // Main function to start preorder traversal
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;  // Vector to store the preorder traversal result
            preorder(root, result);  // Call the helper function
            return result;  // Return the final result
        }
    };
    