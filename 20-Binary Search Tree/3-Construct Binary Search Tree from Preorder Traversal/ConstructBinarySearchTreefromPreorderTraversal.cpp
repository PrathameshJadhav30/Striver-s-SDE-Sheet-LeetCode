// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
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
        // Helper function to build BST from preorder traversal
        TreeNode* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
            // Base case: if we've processed all elements or current value is out of the valid range
            if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal) {
                return nullptr;
            }
    
            // Get the current value and create a node
            int val = preorder[index];
            TreeNode* root = new TreeNode(val);
            index++;  // Move to the next element in preorder
    
            // All values for the left subtree must be < val
            root->left = buildBST(preorder, index, minVal, val - 1);
            
            // All values for the right subtree must be > val
            root->right = buildBST(preorder, index, val + 1, maxVal);
    
            return root;  // Return the root of this subtree
        }
    
        // Main function to be called
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int index = 0;  // To keep track of the current index in preorder traversal
            return buildBST(preorder, index, INT_MIN, INT_MAX);  // Initial bounds are infinite
        }
    };
    