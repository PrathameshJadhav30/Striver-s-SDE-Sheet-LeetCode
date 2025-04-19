// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description
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
        // Main function to start the conversion of sorted array to BST
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return buildBST(nums, 0, nums.size() - 1);
        }
    
        // Helper function to build the BST using recursion
        TreeNode* buildBST(vector<int>& nums, int left, int right) {
            // Base case: when left index exceeds right, the subarray is empty
            if (left > right) {
                return nullptr;
            }
    
            // Choose middle element to maintain balance
            int mid = left + (right - left) / 2;
    
            // Create the current root node with mid value
            TreeNode* root = new TreeNode(nums[mid]);
    
            // Recursively build left subtree using left half of the array
            root->left = buildBST(nums, left, mid - 1);
    
            // Recursively build right subtree using right half of the array
            root->right = buildBST(nums, mid + 1, right);
    
            // Return the root node of this subtree
            return root;
        }
    };
    