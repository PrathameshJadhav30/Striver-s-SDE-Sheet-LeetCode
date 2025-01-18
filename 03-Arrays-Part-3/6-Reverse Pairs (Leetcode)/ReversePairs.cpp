// https://leetcode.com/problems/reverse-pairs/description/
class Solution {
public:
    // Function to perform merge sort and count reverse pairs
    int mergeSort(vector<int>& nums, int left, int right) {
        // Base case: If the subarray has one or no elements, no reverse pairs exist
        if (left >= right) return 0;

        // Calculate the middle index of the current subarray
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves, and count reverse pairs in them
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Count reverse pairs that span the two halves
        int j = mid + 1; // Pointer for the right half
        for (int i = left; i <= mid; ++i) {
            // Move the pointer in the right half until the condition is violated
            while (j <= right && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            // Add the number of valid pairs for the current element in the left half
            count += (j - mid - 1);
        }

        // Merge the two sorted halves into a temporary array
        vector<int> temp(right - left + 1);
        int i = left; // Pointer for the left half
        j = mid + 1;  // Pointer for the right half
        int k = 0;    // Pointer for the temporary array

        // Merge elements in sorted order
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Add remaining elements from the left half (if any)
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Add remaining elements from the right half (if any)
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // Copy the merged elements back into the original array
        for (int i = 0; i < temp.size(); ++i) {
            nums[left + i] = temp[i];
        }

        return count; // Return the total count of reverse pairs for this segment
    }

    // Main function to count reverse pairs in the entire array
    int reversePairs(vector<int>& nums) {
        // Call the helper mergeSort function on the entire array
        return mergeSort(nums, 0, nums.size() - 1);
    }
};