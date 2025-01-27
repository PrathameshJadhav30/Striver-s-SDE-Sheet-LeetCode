// https://leetcode.com/problems/merge-two-sorted-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; // Value of the current node
 *     ListNode *next; // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {} // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next pointer
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // If either list is empty, return the other list
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Case 1: head1's value is less than or equal to head2's value
        if (head1->val <= head2->val) {
            // Recursively merge the remaining elements of head1 and head2
            head1->next = mergeTwoLists(head1->next, head2);
            return head1; // Return head1 as the new head of the merged list
        }
        // Case 2: head2's value is less than head1's value
        else {
            // Recursively merge the remaining elements of head1 and head2
            head2->next = mergeTwoLists(head1, head2->next);
            return head2; // Return head2 as the new head of the merged list
        }
    }
};
