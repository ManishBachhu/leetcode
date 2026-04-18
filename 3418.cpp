class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
             
        vector<vector<int>> dp(m + 1, vector<int>(3, INT_MIN/2));

        for (int i = 0; i < 3; i++) {
            dp[1][i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int x = coins[i - 1][j - 1];
                
                dp[j][2] = max({
                    dp[j - 1][2] + x, // prev col + x
                    dp[j][2] + x,     // prev row + x
                    // skip curr val
                    dp[j - 1][1],
                    dp[j][1]
                });

                dp[j][1] = max({
                    dp[j - 1][1] + x,
                    dp[j][1] + x,
                    dp[j - 1][0],
                    dp[j][0]
                });

                dp[j][0] = max({
                    dp[j][0] + x,
                    dp[j - 1][0] + x
                });
            }
        }

        return dp[m][2];
    }
};
