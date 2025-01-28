// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a temporary dummy node to simplify edge cases
        // (e.g., removing the head of the list)
        ListNode* temp = new ListNode(0);
        temp->next = head;

        // Initialize two pointers: fast and slow
        ListNode* fast = temp;
        ListNode* slow = temp;

        // Move the fast pointer n + 1 steps ahead
        // This creates a gap of n nodes between fast and slow
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until the fast pointer reaches the end of the list
        // At this point, the slow pointer will be just before the node to be removed
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end by skipping it
        ListNode* DelNode = slow->next;      // Node to be deleted
        slow->next = slow->next->next;      // Update the pointer to skip the target node
        delete DelNode;                     // Free memory of the deleted node

        // Update the head of the list in case the first node was removed
        ListNode* newHead = temp->next;
        delete temp;                        // Free memory of the dummy node
        return newHead;
    }
};
