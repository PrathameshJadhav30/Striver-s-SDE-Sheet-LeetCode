// https://leetcode.com/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>  // Include unordered_map for mapping old nodes to new nodes

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            // If the input list is empty, return NULL
            return NULL;
        }

        // Step 1: Create a hash map to map each original node to its corresponding new node
        std::unordered_map<Node*, Node*> m;

        // Step 2: Create the head of the new copied list
        Node* newHead = new Node(head->val);
        
        // Initialize pointers for traversing the original and new lists
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        
        // Map the head of the original list to the head of the new list
        m[head] = newHead;

        // Step 3: Create the next pointers for the new list and populate the map
        while (oldTemp != NULL) {
            // Create a copy of the current node in the original list
            Node* copyNode = new Node(oldTemp->val);
            
            // Map the current original node to the new copied node
            m[oldTemp] = copyNode;
            
            // Link the newly created node to the new list
            newTemp->next = copyNode;
            
            // Move both pointers to the next node in their respective lists
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 4: Assign random pointers for the new list
        oldTemp = head; 
        newTemp = newHead;
        
        while (oldTemp != NULL) {
            // Set the random pointer for the new node by using the map
            newTemp->random = m[oldTemp->random];
            
            // Move to the next node in both lists
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 5: Return the head of the new copied list
        return newHead;
    }
};
