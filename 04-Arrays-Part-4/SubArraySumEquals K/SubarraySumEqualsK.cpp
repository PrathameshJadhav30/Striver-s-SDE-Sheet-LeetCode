// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // Get the size of the input array
        int count = 0; // Initialize count of subarrays with sum equal to k
        vector<int> prefixSum(n, 0); // Vector to store prefix sums

        // Calculate the prefix sum for the array
        prefixSum[0] = arr[0]; // The first prefix sum is the first element
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i]; // Sum up to the current index
        }

        unordered_map<int, int> m; // Hashmap to store prefix sums and their frequencies

        // Iterate through the prefix sums
        for (int j = 0; j < n; j++) {
            // If the current prefix sum is equal to k, we found a subarray
            if (prefixSum[j] == k) {
                count++;
            }

            // Check if there exists a prefix sum such that its removal gives the required sum
            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val]; // Add the count of such prefix sums to the result
            }

            // Add the current prefix sum to the hashmap
            if (m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0; // Initialize if not already in the map
            }
            m[prefixSum[j]]++; // Increment the frequency of the current prefix sum
        }

        return count; // Return the total count of subarrays
    }
};
