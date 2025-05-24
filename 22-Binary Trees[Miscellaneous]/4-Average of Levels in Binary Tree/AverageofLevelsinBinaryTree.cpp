// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;  // Stores average value of each level
        if (!root){
            return result;  // Return empty result if tree is empty
        } 
        
        queue<TreeNode*> q;  // Queue for level-order traversal
        q.push(root);  // Start with the root node

        while (!q.empty()) 
        {
            int size = q.size();  // Number of nodes at the current level
            double sum = 0;       // Sum of node values at this level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop();  // Remove the node from the queue
                sum += node->val;  // Add its value to the sum

                // Enqueue left child if it exists
                if (node->left){
                    q.push(node->left);
                }

                // Enqueue right child if it exists
                if (node->right){
                    q.push(node->right);
                }
            }

            // Compute average for this level and add to result
            result.push_back(sum / size);
        }

        return result;  // Return the list of averages for each level
    }
};
