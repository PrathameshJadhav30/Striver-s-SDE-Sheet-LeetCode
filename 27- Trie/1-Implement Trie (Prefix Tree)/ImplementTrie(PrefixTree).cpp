// https://leetcode.com/problems/implement-trie-prefix-tree/description/
class Trie {
public:
    // Structure representing each node in the Trie
    struct TrieNode {
        TrieNode* children[26];  // Array to hold pointers to child nodes for each lowercase letter
        bool isEnd;              // True if this node marks the end of a word

        // Constructor initializes all children to nullptr and isEnd to false
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;  // Root node of the Trie

    // Constructor initializes the root node
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        TrieNode* node = root;

        // Traverse the Trie character by character
        for (char c : word) {
            int index = c - 'a';  // Convert character to index (0 for 'a', 1 for 'b', ..., 25 for 'z')

            // If the path does not exist, create a new node
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            // Move to the next node
            node = node->children[index];
        }

        // After inserting all characters, mark the end of the word
        node->isEnd = true;
    }

    // Searches for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;

        // Traverse the Trie character by character
        for (char c : word) {
            int index = c - 'a';

            // If at any point the path doesn't exist, word is not present
            if (!node->children[index]) {
                return false;
            }

            // Move to the next node
            node = node->children[index];
        }

        // Return true only if current node marks the end of a word
        return node->isEnd;
    }

    // Checks if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;

        // Traverse character by character
        for (char c : prefix) {
            int index = c - 'a';

            // If path breaks, prefix does not exist
            if (!node->children[index]) {
                return false;
            }

            // Move to the next node
            node = node->children[index];
        }

        // If all characters of prefix are found, return true
        return true;
    }
};
