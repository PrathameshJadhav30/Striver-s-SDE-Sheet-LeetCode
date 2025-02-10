// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    // Function to remove duplicates from a sorted array in-place
    int removeDuplicates(vector<int>& nums) {
        // The variable to track the position to insert the next unique element
        int insertindex = 1;

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Check if the current element is different from the previous one
            if (nums[i - 1] != nums[i]) {
                // Place the current unique element at the insert index
                nums[insertindex] = nums[i];
                // Move the insert index to the next position
                insertindex++;
            }
        }

        // Return the length of the array with unique elements
        return insertindex;
    }
};
