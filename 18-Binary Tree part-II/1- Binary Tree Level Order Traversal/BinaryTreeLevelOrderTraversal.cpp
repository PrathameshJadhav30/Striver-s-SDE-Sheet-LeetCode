// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            // This vector will hold the final level order traversal result
            vector<vector<int>> result;
    
            // If the tree is empty, return an empty result
            if (!root) {
                return result;
            }
    
            // Queue to facilitate BFS (level order traversal)
            queue<TreeNode*> q;
            q.push(root);  // Start with the root node
    
            // Continue while there are nodes to process
            while (!q.empty()) {
                int levelSize = q.size();           // Number of nodes at the current level
                vector<int> currentLevel;           // To store values of nodes at this level
    
                // Process all nodes at the current level
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();     // Get the front node in the queue
                    q.pop();                        // Remove it from the queue
                    currentLevel.push_back(node->val);  // Add its value to the level vector
    
                    // If left child exists, add it to the queue for next level
                    if (node->left) {
                        q.push(node->left);
                    }
    
                    // If right child exists, add it to the queue for next level
                    if (node->right) {
                        q.push(node->right);
                    }
                }
    
                // Add the current level's values to the result
                result.push_back(currentLevel);
            }
    
            // Return the complete level order traversal
            return result;
        }
    };
    