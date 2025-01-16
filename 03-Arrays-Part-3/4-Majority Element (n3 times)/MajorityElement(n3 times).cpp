// https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Initialize variables for two potential candidates and their counts
        int count1 = 0, count2 = 0;
        int can1 = INT_MIN, can2 = INT_MIN;

        // First pass: Identify potential candidates for majority elements
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == can1) {
                // Increment count for the first candidate
                count1++;
            } else if (num == can2) {
                // Increment count for the second candidate
                count2++;
            } else if (count1 == 0) {
                // Update first candidate and reset its count
                can1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                // Update second candidate and reset its count
                can2 = num;
                count2 = 1;
            } else {
                // Decrement counts for both candidates
                count1--;
                count2--;
            }
        }

        // Second pass: Verify the frequency of the candidates
        int c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == can1) {
                c1++;
            }
            if (nums[i] == can2) {
                c2++;
            }
        }

        // Prepare the result vector
        vector<int> result;
        if (c1 > nums.size() / 3) {
            result.push_back(can1);
        }
        if (c2 > nums.size() / 3 && can2 != can1) {
            // Check that second candidate is not a duplicate of the first
            result.push_back(can2);
        }

        return result;
    }
};
