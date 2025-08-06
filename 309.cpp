class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n,0), buy(n,0), sell(n,0);

        buy[0] = -prices[0];
        hold[0] = 0;
        sell[0] = 0;

        for(int i = 1; i < n; i++)
        {
            hold[i] = max(hold[i-1], sell[i-1]);
            buy[i]  = max(buy[i-1], hold[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }
        return max(hold[n-1], sell[n-1]);
    }
};
