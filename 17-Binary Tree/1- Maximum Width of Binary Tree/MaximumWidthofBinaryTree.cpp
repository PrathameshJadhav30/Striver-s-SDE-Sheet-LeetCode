// https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
        int widthOfBinaryTree(TreeNode* root) {
            if (!root) {
                return 0; // If the tree is empty, the width is 0
            } 
    
            // Queue to perform level order traversal, storing node and its index
            queue<pair<TreeNode*, unsigned long long>> q;
            q.push({root, 0});
            int maxWidth = 0;
    
            // BFS traversal of tree
            while (!q.empty()) {
                int size = q.size();
                // To prevent overflow, normalize all indices in this level using the first index
                unsigned long long minIndex = q.front().second;
                unsigned long long first = 0, last = 0;
    
                for (int i = 0; i < size; i++) {
                    auto [node, index] = q.front();
                    q.pop();
    
                    // Normalize index to avoid overflow for deep trees
                    index -= minIndex;
    
                    // Capture first and last indices of current level
                    if (i == 0) {
                        first = index;
                    }
                    if (i == size - 1) {
                        last = index;
                    }
    
                    // Push left child with index 2 * index
                    if (node->left) {
                        q.push({node->left, 2 * index});
                    }
    
                    // Push right child with index 2 * index + 1
                    if (node->right) {
                        q.push({node->right, 2 * index + 1});
                    }
                }
    
                // Calculate width of current level and update maxWidth
                int width = last - first + 1;
                maxWidth = max(maxWidth, width);
            }
    
            return maxWidth; // Return the maximum width among all levels
        }
    };
    