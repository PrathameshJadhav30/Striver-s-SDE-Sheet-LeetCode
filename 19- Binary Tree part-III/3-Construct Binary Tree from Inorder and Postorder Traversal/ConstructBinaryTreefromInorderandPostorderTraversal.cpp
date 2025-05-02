// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
        unordered_map<int, int> inorderMap;  // Map to store index of each value in inorder traversal
        int postIndex;  // Index to track the current root node in postorder traversal
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            postIndex = postorder.size() - 1;  // Start from the last element in postorder
    
            // Store the index of each element in inorder for O(1) access during recursion
            for (int i = 0; i < inorder.size(); i++) {
                inorderMap[inorder[i]] = i;
            }
    
            // Build the tree recursively and return the root
            return build(inorder, postorder, 0, inorder.size() - 1);
        }
    
        // Helper function to recursively build the tree
        TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
            // Base case: if the inorder range is invalid, return null
            if (inStart > inEnd){
               return nullptr;
            } 
    
            // Get the current root value from postorder and decrement postIndex
            int rootVal = postorder[postIndex--];
            TreeNode* root = new TreeNode(rootVal);  // Create the root node
    
            // Find the index of the root in inorder traversal
            int inIndex = inorderMap[rootVal];
    
            // Important: Build right subtree first because we are processing postorder from the end
            root->right = build(inorder, postorder, inIndex + 1, inEnd);
    
            // Build left subtree
            root->left = build(inorder, postorder, inStart, inIndex - 1);
    
            return root;  // Return the constructed subtree rooted at current node
        }
    };
    