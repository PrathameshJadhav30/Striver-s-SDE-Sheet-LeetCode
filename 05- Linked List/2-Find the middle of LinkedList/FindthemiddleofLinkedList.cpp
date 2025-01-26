// https://leetcode.com/problems/middle-of-the-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;                  // Value of the current node
 *     ListNode *next;           // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {} // Default constructor initializing to 0 and nullptr
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor initializing with a value and nullptr
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor initializing with a value and pointer to the next node
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // Slow pointer, advances one step at a time
        ListNode* fast = head; // Fast pointer, advances two steps at a time

        // Traverse the list until fast pointer reaches the end or the node before the end
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next; // Move slow pointer one step forward
            fast = fast->next->next; // Move fast pointer two steps forward
        }

        // Slow pointer now points to the middle node
        return slow;
    }
};
