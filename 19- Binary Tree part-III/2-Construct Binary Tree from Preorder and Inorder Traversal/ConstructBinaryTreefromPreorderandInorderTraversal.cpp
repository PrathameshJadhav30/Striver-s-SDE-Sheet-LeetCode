// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
        // Map to store the index of each value in the inorder traversal
        unordered_map<int, int> inorderMap;
        
        // Index to keep track of current root in preorder traversal
        int preorderIndex = 0;
    
        // Main function to build tree from preorder and inorder traversals
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            // Fill the map with inorder value-to-index mappings
            for (int i = 0; i < inorder.size(); ++i) {
                inorderMap[inorder[i]] = i;
            }
            // Start recursive construction of the binary tree
            return buildSubtree(preorder, 0, inorder.size() - 1);
        }
    
        // Helper function to construct subtree from preorder and inorder bounds
        TreeNode* buildSubtree(vector<int>& preorder, int left, int right) {
            // Base case: if the subtree range is invalid, return null
            if (left > right) {
                return nullptr;
            }
    
            // Select the current root value from preorder traversal
            int rootVal = preorder[preorderIndex++];
            
            // Create a new TreeNode with the root value
            TreeNode* root = new TreeNode(rootVal);
    
            // Get the index of this root value in inorder traversal
            int inorderIndex = inorderMap[rootVal];
    
            // Recursively build the left and right subtrees
            root->left = buildSubtree(preorder, left, inorderIndex - 1);
            root->right = buildSubtree(preorder, inorderIndex + 1, right);
    
            // Return the constructed subtree rooted at 'root'
            return root;
        }
    };
    