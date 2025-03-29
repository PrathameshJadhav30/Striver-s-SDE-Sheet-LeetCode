// https://leetcode.com/problems/min-stack/description/
class MinStack {
    public:
        stack<int> mainStack;  // Standard stack to store all elements
        stack<int> minStack;   // Auxiliary stack to track the minimum elements
    
        MinStack() {
            // Constructor initializes empty stacks
        }
        
        void push(int val) {
            // Push the value onto the main stack
            mainStack.push(val);
            
            // If minStack is empty or the new value is smaller/equal to the current minimum,
            // push it onto the minStack as well to keep track of the minimum
            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            }
        }
        
        void pop() {
            // Ensure stack is not empty before popping
            if (!mainStack.empty()) {
                // If the popped element is also the current minimum, remove it from minStack
                if (mainStack.top() == minStack.top()) {
                    minStack.pop();
                }
                // Remove the element from mainStack
                mainStack.pop();
            }
        }
        
        int top() {
            // Returns the top element of mainStack
            return mainStack.top();
        }
        
        int getMin() {
            // Returns the top element of minStack, which is the current minimum
            return minStack.top();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
    