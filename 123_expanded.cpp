class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k = 2; // num of transactions;
        vector<int> costs(k + 1, INT_MAX), profits(k + 1, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                // book profit from previous transaction
                costs[j] = min(costs[j], prices[i] - profits[j - 1]);
                // capture profit for current transaction
                profits[j] = max(profits[j], prices[i] - costs[j]); 
            }
        }

        return profits[k];
    }
};
