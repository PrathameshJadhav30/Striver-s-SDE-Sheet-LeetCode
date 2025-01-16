// https://leetcode.com/problems/majority-element/description/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialize variables:
        // 'freq' keeps track of the frequency count.
        // 'ans' stores the current candidate for the majority element.
        int freq = 0, ans = 0;

        // Iterate through the array to determine the majority element
        for (int i = 0; i < nums.size(); i++) {
            // If frequency count is zero, set the current element as the candidate
            if (freq == 0) {
                ans = nums[i];
            }
            // If the current element matches the candidate, increment the count
            if (ans == nums[i]) {
                freq++;
            }
            // Otherwise, decrement the count
            else {
                freq--;
            }
        }

        // Return the majority element (guaranteed to exist per problem constraints)
        return ans;
    }
};
