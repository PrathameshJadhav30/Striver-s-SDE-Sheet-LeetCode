class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) 
            return intervals;

        // Sort intervals by the start times using std::sort
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        vector<int> currentInterval = intervals[0];

        // Merging intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= currentInterval[1]) {
                // Merge overlapping intervals
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                // Add non-overlapping interval to result
                result.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }

        // Add the last interval
        result.push_back(currentInterval);
        return result;
    }
};
