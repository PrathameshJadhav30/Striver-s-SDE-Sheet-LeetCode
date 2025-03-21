// https://leetcode.com/problems/valid-parentheses/description/
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to store opening brackets

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // If character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else { // If it's a closing bracket
                // If stack is empty, there's no matching opening bracket
                if (st.empty()) {
                    return false;
                }

                char top = st.top(); // Get the top element of the stack

                // Check if the top of the stack matches the current closing bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Valid pair found, remove the opening bracket from stack
                } 
                else { 
                    return false; // Mismatched bracket
                }
            }
        }

        // If the stack is empty, all brackets are balanced, otherwise return false
        return st.empty();
    }
};
