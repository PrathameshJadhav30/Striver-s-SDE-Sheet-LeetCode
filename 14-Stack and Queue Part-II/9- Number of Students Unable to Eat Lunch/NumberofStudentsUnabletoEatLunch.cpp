// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description
class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int count0 = 0, count1 = 0;  // Count students who prefer circular (0) and square (1) sandwiches
            int n = students.size();  // Number of students (same as number of sandwiches)
            
            // Count the number of students preferring each type of sandwich
            for (int i = 0; i < n; i++) {
                if (students[i] == 0) {
                    count0++;  // Increment count of students who prefer circular sandwiches (0)
                } else {
                    count1++;  // Increment count of students who prefer square sandwiches (1)
                }
            }
            
            // Iterate through the sandwich stack
            for (int i = 0; i < n; i++) {
                if (sandwiches[i] == 0 && count0 > 0) {
                    count0--;  // A student who wants a circular sandwich (0) eats it
                } 
                else if (sandwiches[i] == 1 && count1 > 0) {
                    count1--;  // A student who wants a square sandwich (1) eats it
                } 
                else {
                    // If the top sandwich isn't wanted by any remaining students, return the number of hungry students
                    return count0 + count1;
                }
            }
            
            // If all students got their preferred sandwich, return 0
            return 0;
        }
    };
    