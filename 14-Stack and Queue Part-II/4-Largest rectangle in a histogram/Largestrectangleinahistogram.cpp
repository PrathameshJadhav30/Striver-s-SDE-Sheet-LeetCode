// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st; // Stack to store indices of histogram bars
            int maxArea = 0; // Variable to store the maximum rectangle area
            heights.push_back(0); // Add a sentinel bar of height 0 to process all elements
    
            // Iterate through each bar in the histogram
            for(int i = 0; i < heights.size(); i++) {
                // Process bars that are taller than the current height
                while(!st.empty() && heights[st.top()] > heights[i]) {
                    int height = heights[st.top()]; // Get the height of the top bar
                    st.pop(); // Remove the top bar from the stack
                    
                    int width;
                    // If the stack is empty, it means the popped bar was the smallest so far
                    if(st.empty()) {
                        width = i; // Width is the current index
                    } else {
                        width = i - st.top() - 1; // Calculate width between current and previous index
                    }
                    
                    // Update maxArea if the new rectangle is larger
                    maxArea = max(maxArea, height * width);
                }
                // Push the current index onto the stack
                st.push(i);
            }
            
            return maxArea; // Return the largest found rectangle area
        }
    };
    