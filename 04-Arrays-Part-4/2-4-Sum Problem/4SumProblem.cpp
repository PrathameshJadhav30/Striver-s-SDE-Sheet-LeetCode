// https://leetcode.com/problems/4sum/description/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans; // To store the unique quadruplets
        int n = nums.size(); // Length of the input array

        // Step 1: Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array for the first number of the quadruplet
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first number to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 3: Iterate through the array for the second number of the quadruplet
            for (int j = i + 1; j < n; ) {
                int p = j + 1;       // Pointer for the third number
                int q = n - 1;       // Pointer for the fourth number

                // Step 4: Use two-pointer technique to find pairs
                while (p < q) {
                    // Calculate the sum of the four numbers
                    long long sum = (long long)nums[i] + (long long)nums[j] + 
                                    (long long)nums[p] + (long long)nums[q];

                    // If the sum is less than the target, move the third pointer forward
                    if (sum < tar) {
                        p++;
                    }
                    // If the sum is greater than the target, move the fourth pointer backward
                    else if (sum > tar) {
                        q--;
                    }
                    // If the sum equals the target, add the quadruplet to the result
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // Skip duplicate values for the third number
                        while (p < q && nums[p] == nums[p - 1]) {
                            p++;
                        }

                        // Skip duplicate values for the fourth number
                        while (p < q && nums[q] == nums[q + 1]) {
                            q--;
                        }
                    }
                }

                j++; // Move to the next potential second number
                // Skip duplicate values for the second number
                while (j < n && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
        }

        return ans; // Return the list of unique quadruplets
    }
};
