// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    // Recursive Inorder Traversal
    void inorderRecursive(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorderRecursive(root->left, result);
        result.push_back(root->val);
        inorderRecursive(root->right, result);
    }

    // Iterative Inorder Traversal using Stack
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;  // Move left
            }
            curr = st.top(); 
            st.pop();
            result.push_back(curr->val);  // Visit node
            curr = curr->right;  // Move right
        }
        
        return result;
    }
};