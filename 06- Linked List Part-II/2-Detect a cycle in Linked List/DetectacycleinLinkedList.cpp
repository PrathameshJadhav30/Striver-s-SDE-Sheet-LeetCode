// https://leetcode.com/problems/linked-list-cycle/description/
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
     * Function to detect if a cycle exists in a linked list.
     * Uses Floyd’s Cycle Detection Algorithm (Tortoise and Hare approach).
     *
     * @param head - Pointer to the head of the linked list
     * @return true if a cycle is detected, otherwise false
     */
    bool hasCycle(ListNode *head) {
        // Initialize two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list while ensuring fast and fast->next are not NULL
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps

            // If slow and fast pointers meet, a cycle is detected
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end, there is no cycle
        return false;
    }
};
