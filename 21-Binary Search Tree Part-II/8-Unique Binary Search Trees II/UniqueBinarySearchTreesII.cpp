// https://leetcode.com/problems/unique-binary-search-trees-ii/description
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
    // Main function to generate all unique BSTs with values from 1 to n
    vector<TreeNode*> generateTrees(int n) {
        // If n is 0, return an empty list (no trees possible)
        if (n == 0){
            return {};
        }  
        // Call the recursive function to build trees from 1 to n
        return buildTrees(1, n);
    }

    // Recursive helper function to generate all unique BSTs in range [start, end]
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> trees;

        // Base case: If start > end, there are no nodes to form a tree
        // So, add a nullptr to represent an empty tree
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Iterate through all values from start to end as root nodes
        for (int i = start; i <= end; i++) {
            // Recursively generate all possible left subtrees using values less than i
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            
            // Recursively generate all possible right subtrees using values greater than i
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Combine each left subtree with each right subtree and attach to root
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    // Create a new root node with value i
                    TreeNode* root = new TreeNode(i);

                    // Attach the left and right subtrees
                    root->left = left;
                    root->right = right;

                    // Add the constructed tree to the list
                    trees.push_back(root);
                }
            }
        }

        // Return all trees formed from current range
        return trees;
    }
};
