// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
class Solution {
public:
    // Define a TrieNode structure for storing binary bits (0 and 1)
    struct TrieNode {
        TrieNode* children[2]; // children[0] -> bit 0, children[1] -> bit 1

        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

    TrieNode* root = new TrieNode(); // Root of the Trie

    // Insert a number into the Trie (bitwise representation)
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // 32-bit integer
            int bit = (num >> i) & 1; // Extract the i-th bit
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode(); // Create new node if not exists
            }
            node = node->children[bit]; // Move to the next node
        }
    }

    // Find maximum XOR for a given number with Trie elements
    int getMaxXor(int num) {
        TrieNode* node = root;

        // If Trie is empty, return -1
        if (!node->children[0] && !node->children[1]) {
            return -1;
        }

        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggle = 1 - bit; // We try to find the opposite bit to maximize XOR

            if (node->children[toggle]) {
                // If opposite bit exists, take it and set bit in result
                maxXor |= (1 << i);
                node = node->children[toggle];
            } else {
                // Otherwise, go in same bit direction
                node = node->children[bit];
            }
        }

        return maxXor;
    }

    // Main function to solve the problem
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Sort nums for incremental Trie insertion
        sort(nums.begin(), nums.end());

        // Prepare queries for offline processing: (mi, xi, index)
        vector<tuple<int, int, int>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.emplace_back(queries[i][1], queries[i][0], i); // (mi, xi, original index)
        }

        // Sort queries based on mi to match increasing nums
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(queries.size(), -1);
        int i = 0; // Pointer for nums

        // Process each query
        for (auto& [mi, xi, idx] : offlineQueries) {
            // Insert eligible nums (nums[j] <= mi) into Trie
            while (i < nums.size() && nums[i] <= mi) {
                insert(nums[i]);
                i++;
            }

            // Get max XOR value for current xi
            ans[idx] = getMaxXor(xi);
        }

        return ans;
    }
};
