// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
class Solution {
public:
    // Trie Node structure to store binary representation (0 or 1) paths
    struct TrieNode {
        TrieNode* children[2];  // 0 -> left, 1 -> right

        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

    TrieNode* root = new TrieNode(); // Root of the Trie

    // Insert a number into the Trie (bit by bit from MSB to LSB)
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // for 32-bit integers
            int bit = (num >> i) & 1;  // Extract the i-th bit (0 or 1)
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode(); // create path if missing
            }
            node = node->children[bit]; // move to next level
        }
    }

    // Find the maximum XOR for a given number using the Trie
    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;         // Extract i-th bit
            int toggledBit = 1 - bit;         // To maximize XOR, go opposite bit

            if (node->children[toggledBit]) {
                maxXOR |= (1 << i);           // Set i-th bit in maxXOR
                node = node->children[toggledBit]; // Move to optimal path
            } else {
                node = node->children[bit];   // Fallback to available path
            }
        }
        return maxXOR;
    }

    // Main function to find maximum XOR among all pairs
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0;

        // Step 1: Insert all numbers into Trie
        for (int num : nums) {
            insert(num);
        }

        // Step 2: Find maximum XOR for each number
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(num));
        }

        return maxResult;
    }
};
