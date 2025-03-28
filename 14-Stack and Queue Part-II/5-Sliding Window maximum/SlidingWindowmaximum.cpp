// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> result;  // Stores the maximum values for each window
            deque<int> dq;  // Stores indices of elements in decreasing order
    
            for (int i = 0; i < nums.size(); i++) {
                // Remove elements from the front if they are out of the window range
                if (!dq.empty() && dq.front() < i - k + 1) {
                    dq.pop_front();
                }
    
                // Remove elements from the back that are smaller than the current element
                // This ensures that the largest element is always at the front
                while (!dq.empty() && nums[dq.back()] < nums[i]) {
                    dq.pop_back();
                }
    
                // Add the current element's index to the deque
                dq.push_back(i);
    
                // Store the maximum value of the current window in the result
                // The max value is always at the front of the deque
                if (i >= k - 1) {
                    result.push_back(nums[dq.front()]);
                }
            }
            
            return result;
        }
    };