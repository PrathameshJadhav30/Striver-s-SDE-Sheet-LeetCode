// https://leetcode.com/problems/reverse-linked-list/description/
/**
 * Definition for singly-linked list.
 * This struct defines a singly linked list node.
 * - `val` stores the value of the node.
 * - `next` is a pointer to the next node in the list.
 */
 /*
struct ListNode {
    int val;                // Value stored in the node.
    ListNode *next;         // Pointer to the next node.
    ListNode() : val(0), next(nullptr) {}                            // Default constructor initializes val to 0 and next to nullptr.
    ListNode(int x) : val(x), next(nullptr) {}                       // Constructor initializes val to x and next to nullptr.
    ListNode(int x, ListNode *next) : val(x), next(next) {}          // Constructor initializes val to x and sets next pointer.
};
*/
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;  // Initialize a pointer to keep track of the previous node, starting as NULL.
        ListNode* curr = head; // Current node pointer starts at the head of the list.
        ListNode* next = NULL; // Pointer to temporarily store the next node during reversal.

        // Traverse the list until all nodes are processed.
        while(curr != NULL)
        {
            // Store the next node.
            next = curr -> next;

            // Reverse the current node's pointer.
            curr -> next = prev;

            // Move the previous pointer forward.
            prev = curr;

            // Move the current pointer forward.
            curr = next;
        }

        // After the loop, prev will point to the new head of the reversed list.
        return prev;
    }
};
