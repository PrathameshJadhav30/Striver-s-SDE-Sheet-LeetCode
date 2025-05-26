// https://leetcode.com/problems/clone-graph/description
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Hash map to store the mapping from original node to its clone
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        // If the input node is null, return null
        if (!node){
            return nullptr;
        } 

        // If the node is already cloned, return the clone from the map
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new node (clone) with the same value as the original
        Node* cloneNode = new Node(node->val);
        
        // Store the cloned node in the map to prevent cycles and redundant work
        visited[node] = cloneNode;

        // Recursively clone all the neighbors
        for (auto neighbor : node->neighbors) {
            // Add the clone of the neighbor to the neighbors of the cloneNode
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        // Return the cloned node
        return cloneNode;
    }
};
