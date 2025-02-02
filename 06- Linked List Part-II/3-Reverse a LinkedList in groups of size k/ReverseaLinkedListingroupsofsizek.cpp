// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // Check if there are at least k nodes in the remaining list
        while (count < k) {
            if (temp == NULL) {
                return head; // If there are fewer than k nodes, return the original head (no reversal)
            }
            temp = temp->next;
            count++;
        }

        // Recursively call reverseKGroup for the rest of the linked list after k nodes
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse the current group of k nodes
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next; // Store the next node
            temp->next = prevNode;       // Point current node to the previously reversed group

            prevNode = temp;  // Move prevNode forward
            temp = next;      // Move to the next node in the current group

            count++;
        }

        // Return the new head of the reversed group
        return prevNode;
    }
};
