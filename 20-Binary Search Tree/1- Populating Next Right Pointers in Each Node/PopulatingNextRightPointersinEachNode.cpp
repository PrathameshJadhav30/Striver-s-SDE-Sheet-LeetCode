// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            // If the tree is empty, return null
            if (!root)
            {
                return nullptr;
            } 
    
            // Start with the leftmost node of the tree, initially the root
            Node* leftmost = root;
    
            // Since it's a perfect binary tree, if leftmost->left exists, the next level exists
            while (leftmost->left) 
            {
                // Pointer to traverse nodes at the current level
                Node* head = leftmost;
    
                while (head) 
                {
                    // Connect the left child to the right child of the same parent
                    head->left->next = head->right;
    
                    // If the current node has a next pointer, connect the right child
                    // to the left child of the next node (neighboring subtree)
                    if (head->next) 
                    {
                        head->right->next = head->next->left;
                    }
    
                    // Move to the next node in the current level using next pointers
                    head = head->next;
                }
    
                // Move down to the next level of the tree
                leftmost = leftmost->left;
            }
    
            // Return the root node with all next pointers connected
            return root;
        }
    };
    