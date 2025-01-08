// https://leetcode.com/problems/merge-intervals/description/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If there is only one or no interval, return the input as is
        if (intervals.size() <= 1) 
            return intervals;

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // Compare based on the first element (start time)
        });

        // Initialize the result vector to store merged intervals
        vector<vector<int>> result;
        // Start with the first interval
        vector<int> currentInterval = intervals[0];

        // Iterate through the rest of the intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the next interval
            if (intervals[i][0] <= currentInterval[1]) {
                // If overlapping, merge by updating the end time of the current interval
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                // If not overlapping, add the current interval to the result
                result.push_back(currentInterval);
                // Move to the next interval
                currentInterval = intervals[i];
            }
        }

        // Add the last interval to the result
        result.push_back(currentInterval);
        return result;
    }
};

