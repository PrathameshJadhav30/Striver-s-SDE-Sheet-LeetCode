// https://leetcode.com/problems/linked-list-cycle-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;            // Value of the node
 *     ListNode *next;     // Pointer to the next node
 *     ListNode(int x) : val(x), next(NULL) {}  // Constructor to initialize node value and set next to NULL
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Detect if a cycle exists using the Floyd’s Cycle Detection Algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // Move slow pointer by one step
            fast = fast->next->next;   // Move fast pointer by two steps
            if (slow == fast) {        // Cycle detected
                isCycle = true;
                break;
            }
        }

        // If no cycle is detected, return NULL
        if (!isCycle) {
            return NULL;
        }

        // Find the start of the cycle
        slow = head;                   // Reset slow pointer to the head
        while (slow != fast) {         // Move both pointers one step at a time until they meet
            slow = slow->next;
            fast = fast->next;
        }

        // The meeting point is the start of the cycle
        return slow;
    }
};
