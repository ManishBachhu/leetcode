class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> freq; // start->+1, end->-1
        int ans = 0;

        for(auto x: intervals) {
            freq[x[0]]++;
            freq[x[1]]--;
        }

        int sum = 0;
        for(auto f: freq) {
            sum += f.second;
            ans = max(ans, sum);
        }

        return ans;
    }
};
