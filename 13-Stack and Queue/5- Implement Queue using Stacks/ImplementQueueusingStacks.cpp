// https://leetcode.com/problems/implement-queue-using-stacks/description
class MyQueue {
    stack<int> s1, s2; // Two stacks to implement the queue
    
    // Transfers elements from s1 to s2 to maintain FIFO order
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    public:
        MyQueue() {
            // Constructor initializes an empty queue
        }
        
        // Pushes an element to the back of the queue
        void push(int x) {
            s1.push(x);
        }
        
        // Removes and returns the front element of the queue
        int pop() {
            if (s2.empty()) {
                transfer(); // Transfer elements if s2 is empty
            }
            int front = s2.top();
            s2.pop();
            return front;
        }
        
        // Returns the front element without removing it
        int peek() {
            if (s2.empty()) {
                transfer(); // Transfer elements if s2 is empty
            }
            return s2.top();
        }
        
        // Checks if the queue is empty
        bool empty() {
            return s1.empty() && s2.empty();
        }
    };