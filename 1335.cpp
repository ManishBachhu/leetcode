class Solution {
    vector<vector<int>> dp;

    int scheduleJob(vector<int>& jd, int d, int i, int curDay) {
        // Returns: min difficulty to schedule jobs [i...n-1] with (d-day) days left
        
        // Validate all jobs are done when all days are used
        if(curDay == d) {
            return (i == jd.size()) ? 0 : INT_MAX;
        }
        
        if(dp[curDay][i] != -1)
            return dp[curDay][i];

        int n = jd.size(), todayMax = -1, result = INT_MAX;
        
        // Ensure enough jobs left for remaining days (at least 1 job per day)
        for(int j = i; j <= n - (d - curDay); j++) {
            todayMax = max(todayMax, jd[j]);
            int futureMin = scheduleJob(jd, d, j + 1, curDay + 1);
            
            // Only consider valid future states to avoid overflow
            if(futureMin != INT_MAX) {
                result = min(result, todayMax + futureMin);
            }
        }

        return dp[curDay][i] = result;
    }

public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(d > n)
            return -1;

        dp.resize(d, vector<int>(n + 1, - 1));
        scheduleJob(jd, d, 0, 0);

        return dp[0][0];
    }
};
