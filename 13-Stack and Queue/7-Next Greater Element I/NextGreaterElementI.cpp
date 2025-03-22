// https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nextGreater; // Map to store the next greater element for each number in nums2
            stack<int> st; // Monotonic stack to keep track of elements
    
            // Traverse nums2 to find the next greater elements
            for (int i = 0; i < nums2.size(); i++) 
            {
                // Check if the stack's top element has a next greater element
                while (!st.empty() && st.top() < nums2[i]) 
                {
                    nextGreater[st.top()] = nums2[i]; // Store next greater element in the map
                    st.pop(); // Remove the element from the stack
                }
                st.push(nums2[i]); // Push the current element onto the stack
            }
    
            // If there is no next greater element, store -1 in the map
            while (!st.empty()) 
            {
                nextGreater[st.top()] = -1;
                st.pop();
            }
    
            vector<int> result(nums1.size()); // Result array to store the answers
    
            // Fetch the next greater elements for each number in nums1 using the map
            for (int i = 0; i < nums1.size(); i++) 
            {
                result[i] = nextGreater[nums1[i]];
            }
    
            return result;
        }
    };