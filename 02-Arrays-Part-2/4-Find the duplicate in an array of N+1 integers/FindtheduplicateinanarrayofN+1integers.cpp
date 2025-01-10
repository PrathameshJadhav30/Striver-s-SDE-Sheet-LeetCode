// https://leetcode.com/problems/find-the-duplicate-number/description/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize the slow and fast pointers to the first element
        int slow = nums[0];
        int fast = nums[0];
        
        // Phase 1: Detect the intersection point in the cycle
        do {
            slow = nums[slow];         // Move slow pointer by one step
            fast = nums[nums[fast]];   // Move fast pointer by two steps
        } while (slow != fast);         // Loop until they meet

        // Phase 2: Find the entrance to the cycle
        // Reset one pointer (slow) to the start of the array
        slow = nums[0];
        while (slow != fast) {          // Loop until slow and fast meet
            slow = nums[slow];          // Move slow pointer by one step
            fast = nums[fast];          // Move fast pointer by one step
        }

        // The meeting point is the duplicate number
        return slow;
    }
};
