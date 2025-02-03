// https://leetcode.com/problems/palindrome-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;           // Value of the node
 *     ListNode *next;    // Pointer to the next node
 * 
 *     // Default constructor initializes val to 0 and next to nullptr
 *     ListNode() : val(0), next(nullptr) {}  
 *     
 *     // Constructor initializing val with x and next as nullptr
 *     ListNode(int x) : val(x), next(nullptr) {}  
 *     
 *     // Constructor initializing val with x and next with the given pointer
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  
 * };
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // If the list is empty or contains only one node, it's a palindrome
        if (head == NULL || head->next == NULL) 
            return true;

        ListNode *slow = head, *fast = head;

        // Find the middle of the linked list using slow and fast pointers
        while (fast != NULL && fast->next) 
        {
            slow = slow->next;      // Moves one step at a time
            fast = fast->next->next; // Moves two steps at a time
        }

        // Reverse the second half of the list
        ListNode* prev = NULL;
        while (slow != NULL) 
        {
            ListNode* nextNode = slow->next; // Store next node
            slow->next = prev;  // Reverse current node's pointer
            prev = slow;        // Move prev to current node
            slow = nextNode;    // Move slow to next node
        }

        // Compare the first half and the reversed second half
        ListNode* left = head;
        ListNode* right = prev; // prev now points to the head of the reversed second half
        while (right != NULL) 
        {
            if (left->val != right->val) // If values don't match, it's not a palindrome
                 return false;
            left = left->next;  // Move left pointer forward
            right = right->next; // Move right pointer forward
        }

        return true; // If all nodes matched, it's a palindrome
    }
};
