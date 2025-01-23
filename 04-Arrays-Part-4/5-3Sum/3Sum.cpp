class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size(); // Get the size of the input array
       vector<vector<int>> ans; // Initialize the vector to store the result

       sort(nums.begin(), nums.end()); // Sort the input array

       for(int i = 0; i < n; i++) {
           // Skip the duplicate elements to avoid repeating the same triplet
           if(i > 0 && nums[i] == nums[i - 1]) {
               continue;
           }
           
           int j = i + 1, k = n - 1; // Initialize the two pointers

           while(j < k) {
               int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet
               
               if(sum < 0) {
                   j++; // If the sum is less than zero, increment the left pointer
               } else if(sum > 0) {
                   k--; // If the sum is greater than zero, decrement the right pointer
               } else {
                   // If the sum is zero, add the triplet to the result
                   ans.push_back({nums[i], nums[j], nums[k]});
                   j++;
                   k--;

                   // Skip duplicate elements to avoid repeating the same triplet
                   while(j < k && nums[j] == nums[j - 1]) {
                       j++;
                   }
               }
           }
       }
       return ans; // Return the result containing all unique triplets with sum zero
    }
};
