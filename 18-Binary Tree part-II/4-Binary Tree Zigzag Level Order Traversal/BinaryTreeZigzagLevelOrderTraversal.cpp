// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans; // Final result storing zigzag level order traversal
            if (!root) {
                return ans; // If tree is empty, return empty result
            }
    
            queue<TreeNode*> q; // Queue for level order traversal (BFS)
            q.push(root);
            bool leftToRight = true; // Flag to determine direction of traversal
    
            while (!q.empty()) {
                int size = q.size(); // Number of nodes at current level
                vector<int> level(size); // Temporary vector to store current level's values
    
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front(); // Get the front node in the queue
                    q.pop();
    
                    // Determine index based on traversal direction
                    int index = leftToRight ? i : size - i - 1;
                    level[index] = node->val;
    
                    // Add child nodes to the queue for next level
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
    
                // Flip the traversal direction for next level
                leftToRight = !leftToRight;
                // Add current level's result to final answer
                ans.push_back(level);
            }
    
            return ans;
        }
    };
    