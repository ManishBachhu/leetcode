class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[n] = min(dp[n - k1] + 1, ...., dp[n - kx] + 1)
        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            int min_coins = INT_MAX;
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] < 0 || dp[i - coins[j]] == -1)
                    continue;
                min_coins = min(min_coins, dp[i - coins[j]] + 1);
            }
            if(min_coins == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = min_coins;
            }
        }

        // for(int i = 0; i < dp.size(); i++) {
        //     cout << i <<" : "<< dp[i] << endl;
        // }
        return dp[amount];
    }
};
