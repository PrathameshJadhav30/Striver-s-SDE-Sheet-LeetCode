// https://leetcode.com/problems/find-median-from-data-stream/description/
class MedianFinder {
    // Max heap to store the smaller half of the numbers
    priority_queue<int> left;

    // Min heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> right;

public:
    // Constructor to initialize the MedianFinder object
    MedianFinder() {}

    // Function to add a number to the data structure
    void addNum(int num) {
        // Step 1: Insert the new number into the max heap (left)
        left.push(num);

        // Step 2: Move the largest number from left to right to balance heaps
        right.push(left.top());
        left.pop();

        // Step 3: Ensure left has at most one extra element compared to right
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    // Function to find and return the median
    double findMedian() {
        // If left heap has more elements, return the top element of left (odd number of elements)
        if (left.size() > right.size()) {
            return left.top();
        }
        // If both heaps have equal elements, return the average of tops (even number of elements)
        return (left.top() + right.top()) / 2.0;
    }
};