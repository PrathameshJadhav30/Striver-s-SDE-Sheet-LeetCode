// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
     * Function to find the intersection node of two singly linked lists.
     * If the two linked lists intersect, the function returns the intersection node.
     * If they do not intersect, it returns NULL.
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize two pointers, one for each linked list
        ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists simultaneously
        while (a != b) {
            // If pointer `a` reaches the end of list A, move it to the head of list B
            if (a == NULL) {
                a = headB;
            } else {
                a = a->next;
            }

            // If pointer `b` reaches the end of list B, move it to the head of list A
            if (b == NULL) {
               b = headA;
            } else {
                b = b->next;
            }
        }
        
        // The loop exits when `a` and `b` meet at the intersection node or both become NULL (no intersection)
        return a;
    }
};
