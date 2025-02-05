// https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no need to swap
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize pointers
        ListNode* first = head;          // First node in the current pair
        ListNode* sec = head->next;      // Second node in the current pair
        ListNode* prev = NULL;           // Previous node before the current pair (to reconnect after swapping)

        while (first != NULL && sec != NULL) {
            ListNode* third = sec->next;  // Store the next node after the current pair

            // Swap the nodes
            sec->next = first;           // The second node points to the first node
            first->next = third;         // The first node points to the next node (after the current pair)

            // Reconnect the previous pair with the current swapped pair
            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;              // Update head if this is the first pair
            }

            // Update pointers for the next iteration
            prev = first;                // Move prev to the first node of the current pair
            first = third;               // Move first to the next pair's first node
            if (third != NULL) {
                sec = third->next;       // Move sec to the next pair's second node
            } else {
                sec = NULL;              // No second node in the next pair
            }
        }
        
        return head;
    }
};
