// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * A ListNode represents a node in a singly-linked list.
 */
 /*
struct ListNode {
    int val;          // Value of the node
    ListNode *next;   // Pointer to the next node
    
    // Default constructor initializing value to 0 and next pointer to nullptr
    ListNode() : val(0), next(nullptr) {}

    // Constructor initializing the node with a given value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor initializing the node with a given value and next pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    /**
     * Adds two numbers represented as linked lists.
     * Each node contains a single digit, and digits are stored in reverse order.
     * Returns the sum as a new linked list.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify linked list operations
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy; // Pointer to traverse the new list
        int carry = 0; // Variable to store carry value during addition

        // Traverse both linked lists until all digits are processed
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0; // Sum of current digits plus carry
            
            // If l1 is not null, add its value to sum and move to the next node
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 is not null, add its value to sum and move to the next node
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry from the previous operation
            sum += carry;
            
            // Compute new carry for the next step
            carry = sum / 10;
            
            // Create a new node with the last digit of the sum
            ListNode *node = new ListNode(sum % 10);
            
            // Attach the new node to the result list
            temp->next = node;
            temp = temp->next; // Move temp forward
        }

        // Return the head of the new linked list (excluding dummy node)
        return dummy->next;
    }
};
