// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * Deletes a given node (except the last one) from a singly-linked list.
     * Instead of directly removing the node, it copies the value of the next node
     * into the current node and then bypasses the next node.
     *
     * @param node Pointer to the node that needs to be deleted.
     */
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        
        // Bypass the next node by linking the current node to the node after the next
        node->next = node->next->next;
    }
};
