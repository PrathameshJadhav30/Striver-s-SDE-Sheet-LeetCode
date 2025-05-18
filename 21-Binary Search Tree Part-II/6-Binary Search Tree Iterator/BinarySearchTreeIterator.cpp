// https://leetcode.com/problems/binary-search-tree-iterator/description
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

class BSTIterator {
public:
    // Stack to store the path to the next smallest node
    stack<TreeNode*> stk;

    // Helper function to push all leftmost nodes of the current subtree onto the stack
    void pushLeft(TreeNode* node) {
        while (node) {
            stk.push(node);  // Push current node
            node = node->left;  // Move to left child
        }
    }

    // Constructor: Initializes the iterator and pushes the leftmost path from root
    BSTIterator(TreeNode* root) {
        pushLeft(root); 
    }
    
    // Returns the next smallest element in the BST
    int next() {
        // Get the top element from the stack
        TreeNode* node = stk.top();
        stk.pop();

        // If the node has a right subtree, push all leftmost nodes of that subtree
        if (node->right) {
            pushLeft(node->right);
        }

        // Return the value of the current node
        return node->val;
    }
    
    // Returns true if there are more nodes to traverse
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
