// https://leetcode.com/problems/rotate-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;            // Value of the node
 *     ListNode *next;     // Pointer to the next node
 *     ListNode() : val(0), next(nullptr) {}  // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {}  // Constructor with value
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // Constructor with value and next pointer
 * };
 */

class Solution {
public:
    /**
     * Rotates the linked list to the right by k places.
     * @param head - Pointer to the head of the linked list.
     * @param k - Number of positions to rotate the list.
     * @return - Pointer to the new head of the rotated linked list.
     */
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: if the list is empty, has only one node, or no rotation is needed
        if (!head || !head->next || k == 0) 
            return head;
        
        // Find the length of the list and the last node (tail)
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Reduce k to k % length (rotating by length is the same as no rotation)
        k %= length;
        if (k == 0)
            return head;
        
        // Connect the tail to the head to form a circular linked list
        tail->next = head;
        
        // Find the new tail, which is (length - k) steps away from the current tail
        int stepsToNewHead = length - k;
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        
        // The new head is the node after the new tail
        ListNode* newHead = newTail->next;
        
        // Break the circular connection to form a normal list again
        newTail->next = nullptr;
        
        return newHead;
    }
};
