// https://leetcode.com/problems/backspace-string-compare/description
class Solution {
    public:
        bool backspaceCompare(string s, string t) {
            stack<char> stackS, stackT;  // Stacks to store processed characters of s and t
    
            // Process string s and handle backspaces
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '#') {  // If '#' is encountered, remove last character if stack is not empty
                    if (!stackS.empty()) stackS.pop();
                } else {
                    stackS.push(s[i]);  // Otherwise, push the character onto the stack
                }
            }
    
            // Process string t and handle backspaces
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == '#') {  // If '#' is encountered, remove last character if stack is not empty
                    if (!stackT.empty()) stackT.pop();
                } else {
                    stackT.push(t[i]);  // Otherwise, push the character onto the stack
                }
            }
    
            // Compare the final contents of both stacks
            return stackS == stackT;
        }
    };