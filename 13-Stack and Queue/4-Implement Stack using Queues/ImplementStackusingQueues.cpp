// https://leetcode.com/problems/implement-stack-using-queues/description
class MyStack {
    queue<int> q;  // Using a single queue to implement the stack

public:
    MyStack() {}

    // Push operation: Inserts an element at the top of the stack
    void push(int x) {
        q.push(x);  // Push the new element into the queue
        int size = q.size();
        
        // Rotate the queue so that the last pushed element moves to the front
        while (size-- > 1) {
            q.push(q.front()); // Move the front element to the back
            q.pop();  // Remove the front element
        }
    }

    // Pop operation: Removes and returns the top element
    int pop() {
        int topElement = q.front(); // Get the front element (which acts as top of stack)
        q.pop();  // Remove the front element
        return topElement;
    }

    // Top operation: Returns the top element without removing it
    int top() {
        return q.front(); // The front element is always the top of the stack
    }

    // Empty operation: Checks if the stack is empty
    bool empty() {
        return q.empty(); // Returns true if queue is empty, false otherwise
    }
};