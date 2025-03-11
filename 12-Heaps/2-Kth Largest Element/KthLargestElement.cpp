// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
           
            for (int i = 0; i < nums.size(); i++) {
                minHeap.push(nums[i]);  // Push element into min-heap
                
                if (minHeap.size() > k) {
                    minHeap.pop();  // Remove the smallest element if heap size exceeds k
                }
            }
            
            return minHeap.top();  // The root of the min-heap is the kth largest element
        }
    };