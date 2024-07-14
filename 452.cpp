class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        // intervals[i] = [start, end]
        // We need to find the number of intersections between the intervals
        // Two intervals have an intersection if start of one interval is 
        //  less than end of the other interval
        // We sort intervals based on the start and traverse the vector
        // init curr_interval = intervals[0]
        // for every new interval, compare the new->start with curr_interval->end
        // if end > start, curr_interval = [new->start, min(curr_interval->end, new->end)]
        // else, increment the count of arrows and set curr_interval = new_interval
        // return count of arrows

        // Time Complexity : O(nLogn)
        // Space Complexity : O(1)

        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> curr_interval = intervals[0];
        int arrows = 0;
        for(auto next_interval : intervals) {
            if(next_interval[0] <= curr_interval[1]) {
                curr_interval[0] = next_interval[0];
                curr_interval[1] = min(curr_interval[1], next_interval[1]);
            }
            else {
                arrows++;
                curr_interval = next_interval;
            }
        }
        return arrows + 1;
    }
};