// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create an unordered set to store the unique elements from the input array.
        // This ensures that we can check for the existence of elements in O(1) time.
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Variable to track the length of the longest consecutive sequence found.
        int longestconsecutive = 0;

        // Iterate through each number in the set
        for (int num : numSet) 
        {
            // We only start building a sequence if `num-1` is not present in the set.
            // This ensures we only consider the starting number of a sequence.
            if (numSet.find(num - 1) == numSet.end())
             {
                // Start building the consecutive sequence from the current number
                int currentNum = num;
                int currentconsecutive = 1; // Initial sequence length is 1 (current number itself)

                // While the next number (`currentNum + 1`) exists in the set, increment the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) 
                {
                    currentNum++; // Move to the next number in the sequence
                    currentconsecutive++; // Increment the length of the current consecutive sequence
                }

                // Update the longest consecutive streak if the current sequence is longer
                longestconsecutive = max(longestconsecutive, currentconsecutive);
            }
        }

        // Return the length of the longest consecutive sequence found
        return longestconsecutive;
    }
};
