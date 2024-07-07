class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Problem statement:
        // intervals[i] = [starti, endi], sorted in ascending order by starti
        // newInterval = [curr_start, curr_end]
        // insert newInterval into intervals, merge overlapping intervals

        // Solution Approach:
        // Create a new vector to store the result
        // Traverse the intervals vector
        // if the current interval is before the newInterval, add it to the result
        // if curr_start <= end, then modify newInterval 
        // to [starti, max(endi, curr_end)]
        // if the current interval is after the newInterval, add the 
        // newInterval to the result and replace the current interval with the newInterval
        // return the result

        vector<vector<int>> result;
        int n = intervals.size();

        for(auto interval: intervals) {
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }
            else if (interval[0] <= newInterval[1]) {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
            else {
                result.push_back(newInterval);
                newInterval = interval;
            }
        }
        result.push_back(newInterval);
        return result;
    }
};