// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
class KthLargest {
    // Min-heap to store the top k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;  // The 'k' in 'kth largest'

public:
    // Constructor initializes the class with k and the initial stream of numbers
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        // Add each number in the initial stream to the heap
        for (int num : nums) 
        {
            add(num);  // Reuse the add function to maintain heap property
        }
    }
    
    // Adds a new number to the stream and returns the kth largest element
    int add(int val) {
        // If heap size is less than k, simply push the new value
        if (minHeap.size() < k)
        {
            minHeap.push(val);
        }
        // If the new value is greater than the smallest in the heap
        else if (val > minHeap.top()) 
        {
            minHeap.pop();         // Remove the smallest
            minHeap.push(val);     // Insert the new larger value
        }
        // Return the kth largest element, which is the smallest in the heap
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */