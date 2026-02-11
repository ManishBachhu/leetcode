class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        // pq.push(intervals[0][1]);
        for(auto x: intervals) {
            while(!pq.empty() && pq.top() <= x[0])
                pq.pop();
            pq.push(x[1]);
            int s = pq.size();
            ans = max(ans, s);
        }

        return ans;
        
    }
};
