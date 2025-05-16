// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description
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

    // Helper function to perform inorder traversal on a BST
    // and collect the node values into the 'result' vector.
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return; // Base case: if the node is null, do nothing
        }
        inorder(root->left, result);     // Traverse the left subtree
        result.push_back(root->val);     // Visit the current node
        inorder(root->right, result);    // Traverse the right subtree
    }

    // Main function to return all elements from both BSTs in sorted order
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        // Perform inorder traversal on both trees to get sorted arrays
        inorder(root1, v1);
        inorder(root2, v2);

        vector<int> merged; // Final merged sorted array
        int i = 0, j = 0;

        // Merge the two sorted arrays using two pointers
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                merged.push_back(v1[i++]); // Add the smaller element to merged
            } else {
                merged.push_back(v2[j++]); // Add the smaller or equal element
            }
        }

        // Add remaining elements from v1, if any
        while (i < v1.size()) {
            merged.push_back(v1[i++]);
        }

        // Add remaining elements from v2, if any
        while (j < v2.size()) {
            merged.push_back(v2[j++]);
        }

        return merged; // Return the fully merged sorted list
    }
};
