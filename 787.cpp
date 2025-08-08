class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));

        for(int i = 0; i <= k+1; i++)
            dp[i][src] = 0;

        for(int i = 1; i <= k+1; i++)
        {
            for(auto &f: flights)
            {
                int s = f[0], d = f[1], c = f[2];

                if(dp[i-1][s] != INT_MAX)
                    dp[i][d] = min(dp[i][d], dp[i-1][s] + c);
            }
        }
        if(dp[k+1][dst] != INT_MAX)
            return dp[k+1][dst];
        else
            return -1;
    }
};
